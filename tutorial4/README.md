pkg-config with cmake
==================================

Description
-----------
cmake에서 pkg-config를 이용한 library import 방법
cmake --help-module-list 명령어를 통해서 현재 cmake에서 지원하는 find_package들을 확인할 수 있다.
예) FindSDL
glib-2.0의 경우, FindGLIB* 이런 것들이 존재하지 않는다.
따라서 find_package는 사용할 수 없고, pkg-config를 이용해서 library를 project에 Import해야 한다.

Prerequisites
=============
This codes are tested under Ubuntu 18.04 64bit LTS.
pkg-config and glib-2.0 should be installed

	$pkg-config glib-2.0 --cflags --libs

Building
========
    $ cd build
    $ cmake ..
    $ make

Reference
========
https://github.com/jacking75/examples_CMake/blob/master/find_package_And_pkg_check_modules.md