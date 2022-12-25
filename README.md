libkernaux
==========

[![Build status](https://github.com/tailix/libkernaux/actions/workflows/main.yml/badge.svg)](https://github.com/tailix/libkernaux/actions/workflows/main.yml)
[![Build status (FreeBSD)](https://api.cirrus-ci.com/github/tailix/libkernaux.svg?task=Main%20(FreeBSD))](https://cirrus-ci.com/github/tailix/libkernaux)

Auxiliary library for kernel development.

[Topic on OSDev.org forum](https://forum.osdev.org/viewtopic.php?f=1&t=37958).



Table of contents
-----------------

* [Overview](#libkernaux)
* [Table of contents](#table-of-contents)
* [API](#api)
  * [Headers](#headers)
  * [Definitions](#definitions)
  * [Global variables](#global-variables)
* [Configuration](#configuration)
  * [Non-default options](#non-default-options)
  * [Default options](#default-options)
* [Tips](#tips)
  * [Installation](#installation)
  * [Development](#development)
  * [Cross](#cross)



API
---

### Headers

We use [semantic versioning](https://semver.org) for stable APIs. Stable APIs
may only change when major version number is increased (or minor while major is
zero). Work-in-progress APIs can change at any time.

* libc replacement (*work in progress*)
  * [ctype.h](/libc/include/ctype.h)
  * [errno.h](/libc/include/errno.h)
  * [inttypes.h](/libc/include/inttypes.h)
  * [setjmp.h](/libc/include/setjmp.h)
  * [stdlib.h](/libc/include/stdlib.h)
  * [string.h](/libc/include/string.h)
  * [sys/types.h](/libc/include/sys/types.h)




Configuration
-------------

Because this library has no external dependencies, we use **autoconf** features
to control behavior of the library, and packages to choose it's components.
Configuration options also follow the [semantic versioning](https://semver.org)
scheme and are split into stable and work-in-progress ones. Here we cover only
stable options.

### Non-default options

#### Features

* `--enable-checks` - enable usual tests
* `--enable-checks-all` - enable all checks
* `--enable-checks-cppcheck` - enable cppcheck
  Jinja2
* `--enable-pkg-config[=PATH]` - install pkg-config files
  [PATH='${libdir}/pkgconfig']

#### Packages

* `--with-libc` - provides the replacement for some standard C functions.
  Useful in freestanding environment, where no libc is present.

### Default options

#### Features

* `--(enable|disable)-float` - floating-point arithmetic
* `--(enable|disable)-werror` - fail on warning (`CFLAGS+='-Werror'`)



Tips
----

### Installation

```
./autogen.sh # if present
./configure
make
sudo make install
sudo ldconfig # on GNU/Linux
```

This is just a usual library. You can use most of it's APIs in hosted
environment.

### Development

```
./autogen.sh # if present
./configure --enable-checks # or --enable-checks-all, but see prerequisites
make
```

You can test with `make check`.

#### See also

* [GitHub Actions](/.github/) for **GNU/Linux** build environment
* [Cirrus CI](/.cirrus.yml) for **FreeBSD** build environment
* [sourcehut CI](/.openbsd.yml) for **OpenBSD** build environment

### Cross

Create configuration script with `./autogen.sh` (if present).

Let's assume that your target triplet is `i386-elf`. Configure with
[cross-compiler](https://wiki.osdev.org/GCC_Cross-Compiler) in `$PATH` to make
without it in `$PATH`:

```
./configure \
  --host='i386-elf' \
  --disable-shared \
  --enable-freestanding \
  --with-libc \
  CC="$(which i386-elf-gcc)"
```

The variables include `AR`, `AS`, `CC`, `CCAS`, `LD`, `NM`, `OBJDUMP`, `RANLIB`,
`STRIP`. See the generated `config.log` for more information.

To install into specific directory use full path: `DESTDIR="$(pwd)/dest" make
install` instead of `DESTDIR=dest make install`.
