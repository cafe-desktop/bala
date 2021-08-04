## What is Bala?
Bala is a programming language that aims to bring modern programming
language features to GNOME developers without imposing any additional
runtime requirements and without using a different ABI compared to
applications and libraries written in C.

`balac`, the Bala compiler, is a self-hosting compiler that translates
Bala source code into C source and header files. It uses the GObject
type system to create classes and interfaces declared in the Bala source
code.

The syntax of Bala is similar to C#, modified to better fit the GObject
type system. Bala supports modern language features as the following:

 * Interfaces
 * Properties
 * Signals
 * Foreach
 * Lambda expressions
 * Type inference for local variables
 * Generics
 * Non-null types
 * Assisted memory management
 * Exception handling

Bala is designed to allow access to existing C libraries, especially
GObject-based libraries, without the need for runtime bindings. All that
is needed to use a library with Bala is an API file, containing the class
and method declarations in Bala syntax. Bala currently comes with
bindings for GLib and GTK+.

Using classes and methods written in Bala from an application written in
C is not difficult. The Bala library only has to install the generated
header files and C applications may then access the GObject-based API of
the Bala library as usual. It should also be easily possible to write a
bindings generator for access to Bala libraries from applications
written in e.g. C# as the Bala parser is written as a library, so that
all compile-time information is available when generating a binding.

More information about Bala is available at [https://wiki.gnome.org/Projects/Bala/](https://wiki.gnome.org/Projects/Bala/)


## Building Bala
Instructions on how to build the latest version of Bala.
These can be modified to build a specific release.

### Step One:
Install the following packages:

 * a C compiler, e.g. GCC
 * a C library, e.g. glibc
 * glib (>= 2.48)
 * flex
 * bison
 * Graphviz (libgvc) (>= 2.16) to build baladoc
 * make
 * autoconf
 * autoconf-archive
 * automake
 * libtool


### Step Two:
Decide where the Bala compiler is to be found.

Bala is self-hosting so it needs another Bala compiler to compile
itself.  `balac` is the name of the executable and can be:

 * installed from an existing package
 * built from a source tarball
 * built from the [Bala bootstrap module](https://gitlab.gnome.org/Archive/bala-bootstrap)

If you have an existing `balac` installed then move on to step three.

If you don't have an existing version of Bala installed (i.e. because you're
bootstrapping or cross-compiling) then a source tarball or the bala-bootstrap
module contain pre-compiled C files from the Bala sources. These can be used
to bootstrap `balac`.

Source tarballs can be downloaded via:

https://wiki.gnome.org/Projects/Bala/Release

or the bala-bootstrap module is available at:

https://gitlab.gnome.org/Archive/bala-bootstrap


Here is an example on how to download and compile from a Bala release tarball.
In this example it is release version 0.42.3:

```sh
curl --silent --show-error --location https://download.gnome.org/sources/bala/0.42/bala-0.42.3.tar.xz --output bala-bootstrap.tar.xz
tar --extract --file bala-bootstrap.tar.xz
cd bala-bootstrap
./configure --prefix=/opt/bala-bootstrap
make && sudo make install
```

The configure script will check if `balac` can be found in PATH. If not then
`balac` is bootstrapped from the C source files in the tarball.
If you do not wish to install the bootstrapped version of `balac` it can be
found in `bala-bootstrap/compiler/balac` This is a libtool wrapper script
that makes the libraries in the build directory work together.


An example of downloading and compiling from the bootstrap module:

```sh
git clone https://gitlab.gnome.org/Archive/bala-bootstrap
cd bala-bootstrap
touch */*.stamp
BALAC=/no-balac ./configure --prefix=/opt/bala-bootstrap
make && sudo make install
```

### Step Three:
Compiling the newest Bala from the repository using a pre-installed `balac`:

```sh
git clone https://gitlab.gnome.org/GNOME/bala
cd bala
./autogen.sh
make && sudo make install
```

To use `balac` from a bootstrapped build detailed in step two use:

```sh
git clone https://gitlab.gnome.org/GNOME/bala
cd bala
BALAC=/opt/bala-bootstrap/bin/bala ./autogen.sh
make && sudo make install
```

### Compiling Different Bala Versions
Maybe you now want to compile Bala with the new version you have just installed.
Then you simply clean the version files and start the build. Be warned that
`git clean -dfx` **will remove all untracked files** from the source tree:

```sh
git clean -dfx
./autogen.sh
make && sudo make install
```

If you wish to build a specific release, for example 0.40.11:

```sh
git checkout 0.40.11
git clean -dfx
./autogen.sh
make && sudo make install
```
