from setuptools import find_packages
from setuptools import setup

setup(
    name='sun_pkg',
    version='0.0.0',
    packages=find_packages(
        include=('sun_pkg', 'sun_pkg.*')),
)
