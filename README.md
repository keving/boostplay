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



