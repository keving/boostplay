# boostplay
Playing with Boost Python / following tutorials.


# greeting


    kagy@kagy3:~/git/boostplay/hello$ c++ -I /usr/include/boost/ -I /usr/include/python2.7 -fPIC -c  hello.cpp
    kagy@kagy3:~/git/boostplay/hello$ c++ -shared -Wl,--export-dynamic hello.o -lboost_python -o hello_ext.so
    kagy@kagy3:~/git/boostplay/hello$ python
    Python 2.7.13 (default, Nov 24 2017, 17:33:09) 
    [GCC 6.3.0 20170516] on linux2
    Type "help", "copyright", "credits" or "license" for more information.
    >>> import hello_ext
    >>> print hello_ext.greet()
    hello, world
    >>> 

# car

    kagy@kagy3:~/git/boostplay/hello$ c++ -I /usr/include/boost/ -I /usr/include/python2.7 -fPIC -c car.cpp -o car_ext.o
    kagy@kagy3:~/git/boostplay/hello$ c++ -shared -Wl,--export-dynamic car_ext.o -lboost_python -o car_ext.so
    kagy@kagy3:~/git/boostplay/hello$ python
    Python 2.7.13 (default, Nov 24 2017, 17:33:09) 
    [GCC 6.3.0 20170516] on linux2
    Type "help", "copyright", "credits" or "license" for more information.
    >>> import car_ext
    >>> mini = car_ext.Car("mini", 20)
    >>> mini.increaseSpeed()
    >>> mini.drive()
    Driving mini at 50mph
    >>> 

# library


    kagy@kagy3:~/git/boostplay/library$ python3 setup.py clean
    running clean
    removing 'build/temp.linux-x86_64-3.5' (and everything under it)
    removing 'build'
    kagy@kagy3:~/git/boostplay/library$ python3 setup.py build_ext --inplace
    running build_ext
    kagy@kagy3:~/git/boostplay/library$ ls -l
    total 48
    -rw-r--r-- 1 kagy primarygroup  3187 May 19 14:08 library.c
    -rwxr-xr-x 1 kagy primarygroup 33288 May 19 14:08 library.cpython-35m-x86_64-linux-gnu.so
    -rw-r--r-- 1 kagy primarygroup   518 May 19 13:51 library.h
    -rw-r--r-- 1 kagy primarygroup   238 May 19 13:56 setup.py
    kagy@kagy3:~/git/boostplay/library$ python3
    Python 3.5.3 (default, Jan 19 2017, 14:11:04) 
    [GCC 6.3.0 20170118] on linux
    Type "help", "copyright", "credits" or "license" for more information.
    >>> import library
    >>> library.version()
    'Version 1.0'
    >>> 
    

