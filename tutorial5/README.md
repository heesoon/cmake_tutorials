ExternalProject with cmake
==================================

Description
-----------
googletest framework을 cmake ExternalProject를 이용해서 사용해본다.

아래 페이지에 cmake FetchContent를 이용하는 방법도 있으나, 3.12 이상의 버전에서 지원하기    
때문에 여기서는 하위 호환성을 위해서 ExternalProject방식을 테스트해 본다.

Prerequisites
=============
This codes are tested under Ubuntu 18.04 64bit LTS.      

googletest framework require pthread

Building
========
    $ cd build
    $ cmake ..
    $ make

gtest testing
========
    $ cd build
    $ ./tutorial5
