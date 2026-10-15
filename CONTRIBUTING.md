Before you begin:

- The file is retail `sf33rd.xbe`. SHA-256 `a04b2e91d65096f438790c14c95cf17272ef50c345b7a071d703a79d2ee9f3d6`. Size 4,526,080 bytes. See [docs/xbe.md](docs/xbe.md).
- Read [docs/decompiling.md](docs/decompiling.md). A name in `config/sf33rd/symbols/funcs.txt` is a body that matches source.
- `make check` runs the unit tests and, when the XBE is present, checks it.

Do not commit `sf33rd.xbe`, a PDB, `SF33RDXB.AFS`, shader binaries, or anything under `build/`. `tools/candidates.py` must not write `funcs.txt`.
