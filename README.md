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

# Find clalbacks with root

```
> root
root [0] gSystem->Load("${INSTALL_DIR}/lib64/libtestlib.so");
root [1] poptest1();
poptest1 5 56
root [2] URZoomAllXAsLast(0)
URZoomAllXAsLast 0
```
