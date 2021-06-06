library header and lib의 path를 manual로 추가해서 cmake 작성
==================================

Description
-----------
실행 target의 library path를 잡아주는 순서는 아래와 같이 하는 것이 좋은 방법이다.

1) find_package 사용 (해당 .make 패키지가 존재할 경우만 가능)

2) 1)을 사용할 수 없는 경우, pkg-config module을 사용해서 자동 위치 설치 (tutorial4번에 해당)
    - library가 library.pc 파일이 없을 경우, pc 파일이 pkg-config가 search하는 path에 존재하지 않을 경우 pkg-config library 자동 path 설정은 실패한다.

3) 1), 2)를 모두 사용할 수 없을 경우, 현재 예제처럼 강제로 잡아 줄 수 있다.        


3)의 방법은 아래와 같음. (CMakeLists.txt 참조 - <strong>imported_glib2</strong> 이름으로 설치)

1) add_library를 imported target으로 사용한다.
    - imported library는 library소스를 빌드하는 것은 아니고, 빌드된 외부 library를 사용하겠다는 의미로 해석하면 쉬움.

    ``` 
        add_library(imported_glib2 SHARED IMPORTED)
    ```

2) set_target_properties 설정
    - imported될 library의 위치를 지정해 준다. 다른 property는 cmake 문서 참조

    ``` 
        set_target_properties(imported_glib2
	        PROPERTIES IMPORTED_LOCATION /usr/lib/x86_64-linux-gnu/libglib-2.0.so
        )
    ```

3) 추가적으로 include_directories에 해더 파일 위치 지정

    ``` 
        include_directories(
            ${CMAKE_SOURCE_DIR}/include
            /usr/include/glib-2.0
        )
    ```

4) target_link_libraries에 위에서 설정한 library path 추가
    ``` 
        target_link_libraries(${PROJECT_NAME}
            imported_glib2
        )
    ```

Prerequisites
=============
This codes are tested under Ubuntu 18.04 64bit LTS.    
pkg-config and glib-2.0 should be installed

Building
========
    $ cd build
    $ cmake ..
    $ make