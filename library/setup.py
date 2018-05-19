from distutils.core import setup, Extension

module = Extension('library', sources = ['library.c'])

setup (name = 'PackageName',
       version = '1.0',
       description = 'This is a package for library',
       ext_modules = [module])