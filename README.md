# Installation

```
meson setup build
cd build
meson configure --prefix="${INSTALL_DIR}"
ninja
ninja install
```

# Run the test app

```
${INSTALL_DIR}/bin/testapp
```

Callbacks are not called

# Using root

```
Sources/root-context-menu/build on  main took 1m36s ❯ root
   ------------------------------------------------------------------
  | Welcome to ROOT 6.30/02                        https://root.cern |
  | (c) 1995-2023, The ROOT Team; conception: R. Brun, F. Rademakers |
  | Built for linuxx8664gcc on Jan 25 2024, 06:53:38                 |
  | From heads/master@tags/v6-30-02                                  |
  | With c++ (GCC) 13.2.1 20231205 (Red Hat 13.2.1-6)                |
  | Try '.help'/'.?', '.demo', '.license', '.credits', '.quit'/'.q'  |
   ------------------------------------------------------------------

root [0] gSystem->Load("/home/pacaud/Sources/INSTALL-root-test/lib64/libtestlib.so");
root [1] .L ../test.cc 
root [2] customContextMenu()
Info in <TCanvas::MakeDefCanvas>:  created default TCanvas with name c1
root [3] URZoomAllXAsLast 22ccc40
```

It works
