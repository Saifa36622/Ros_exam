from setuptools import find_packages
from setuptools import setup

setup(
    name='sun_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('sun_interfaces', 'sun_interfaces.*')),
)
