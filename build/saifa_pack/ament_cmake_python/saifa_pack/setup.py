from setuptools import find_packages
from setuptools import setup

setup(
    name='saifa_pack',
    version='0.0.0',
    packages=find_packages(
        include=('saifa_pack', 'saifa_pack.*')),
)
