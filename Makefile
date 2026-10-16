PYTHON := python3
VA ?= 0x125FF7

.PHONY: info scan disasm xref candidates progress shaders check test

info:
	$(PYTHON) tools/info.py

scan:
	$(PYTHON) tools/scan.py

disasm:
	$(PYTHON) tools/disasm.py $(VA)

xref:
	@test -n "$(S)" || { echo "usage: make xref S=Game.c"; exit 2; }
	$(PYTHON) tools/xref.py "$(S)"

candidates:
	$(PYTHON) tools/candidates.py

progress:
	$(PYTHON) tools/progress.py

shaders:
	$(PYTHON) tools/xvs.py
	$(PYTHON) tools/xpu.py

test:
	$(PYTHON) -m unittest discover -s tests -v

check: test
	$(PYTHON) tools/check_xbe.py
