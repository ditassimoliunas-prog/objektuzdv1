.PHONY: help build test clean docs run install

# ========== KONFIGŪRACIJA ==========
BUILD_DIR := build
DOCS_DIR := dokumentacija
CMAKE := cmake
MAKE := make

ifeq ($(OS),Windows_NT)
	CMAKE_GENERATOR := -G "Visual Studio 16 2019"
	RUN_TEST := .\$(BUILD_DIR)\Release\test_programa.exe
	RUN_PROG := .\$(BUILD_DIR)\Release\programa.exe
else
	CMAKE_GENERATOR :=
	RUN_TEST := ./$(BUILD_DIR)/test_programa
	RUN_PROG := ./$(BUILD_DIR)/programa
endif

# ========== PAGRINDINIS TIKSLAS ==========
help:
	@echo "=================================="
	@echo "ObjektinisUzdavinys v2.0 - Makefile"
	@echo "=================================="
	@echo ""
	@echo "Turimi tikslai:"
	@echo "  make build      - Kompiliuoti projektą"
	@echo "  make test       - Vykdyti unit testus"
	@echo "  make run        - Paleisti pagrindinę programą"
	@echo "  make docs       - Sugeneruoti Doxygen dokumentaciją"
	@echo "  make clean      - Išvalyti build direktorijų"
	@echo "  make install    - Pilnai suprojektuoti ir sukompiliuoti"
	@echo ""

# ========== BUILD TIKSLAS ==========
build: $(BUILD_DIR)
	@echo "[BUILD] Konfigūruojame CMake..."
	cd $(BUILD_DIR) && $(CMAKE) $(CMAKE_GENERATOR) ..
	@echo "[BUILD] Kompiliuojame projektą..."
	cd $(BUILD_DIR) && $(CMAKE) --build . --config Release
	@echo "[BUILD] ✓ Kompiliavimas sėkmingas!"

$(BUILD_DIR):
	@echo "[MKDIR] Kuriame $(BUILD_DIR) direktorijų..."
	mkdir -p $(BUILD_DIR)

# ========== TESTŲ TIKSLAS ==========
test: build
	@echo "[TEST] Vykdome unit testus..."
	$(RUN_TEST)
	@echo "[TEST] ✓ Testai baigti!"

# ========== DOKUMENTACIJOS TIKSLAS ==========
docs:
	@echo "[DOCS] Sugeneruojame Doxygen dokumentaciją..."
	@if command -v doxygen >/dev/null 2>&1; then \
		doxygen Doxyfile; \
		echo "[DOCS] ✓ Dokumentacija sugeneruota: $(DOCS_DIR)/html/index.html"; \
	else \
		echo "[DOCS] ✗ Klaida: doxygen nsuinstaliuotas!"; \
		echo "Parsisiųskite iš https://www.doxygen.nl/download.html"; \
		exit 1; \
	fi

# ========== PALEIDIMO TIKSLAS ==========
run: build
	@echo "[RUN] Paleidžiame pagrindinę programą..."
	$(RUN_PROG)

# ========== VALYMO TIKSLAS ==========
clean:
	@echo "[CLEAN] Išvalome build direktorijų..."
	rm -rf $(BUILD_DIR)
	@echo "[CLEAN] ✓ Build direktorija išvalyta!"

# ========== PILNOS DIEGIMO TIKSLAS ==========
install: clean build test docs
	@echo ""
	@echo "=================================="
	@echo "✓ PILNAS DIEGIMAS SĖKMINGAS!"
	@echo "=================================="
	@echo ""
	@echo "Tolimi žingsniai:"
	@echo "  1. Paleisti programą: make run"
	@echo "  2. Peržiūrėti dokumentaciją: open $(DOCS_DIR)/html/index.html"
	@echo "  3. Patikrinti README.md šio projekto"
	@echo ""

# ========== INFO TIKSLAS ==========
info:
	@echo "Projekto informacija:"
	@echo "  Pavadinimas: ObjektinisUzdavinys"
	@echo "  Versija: v2.0"
	@echo "  Kalba: C++17"
	@echo "  Kompiliatorius: MSVC / GCC / Clang"
	@echo ""
	@echo "Build direktorija: $(BUILD_DIR)"
	@echo "Dokumentacijos direktorija: $(DOCS_DIR)"
	@echo ""
