import pathlib
from setuptools import setup, find_packages

HERE = pathlib.Path(__file__).parent
README_CONTENT = (HERE / "README.md").read_text(encoding='utf-8')

setup(name='tptp-parser',
    version='0.0.1',
    description='A fast TPTP-parser for Python3',
    description_content_type='text/plain',
    long_description=README_CONTENT,
    long_description_content_type='text/markdown',
    author='Marco Träger',
    author_email='marco.traeger@gmail.com',
    url='https://github.com/leoprover/tptp-parser',
    classifiers=[
        'Development Status :: 2 - Pre-Alpha',
        'Environment :: Console',
        'Environment :: Web Environment',
        'Intended Audience :: Developers',
        'Intended Audience :: Information Technology',
        'Intended Audience :: Science/Research',
        'Topic :: Scientific/Engineering :: Artificial Intelligence',
        'Programming Language :: Python :: 3.5',
        'Programming Language :: Python :: 3.6',
        'Programming Language :: Python :: 3.7',
        'Programming Language :: Python :: 3.8',
        'Programming Language :: Python :: 3.9',
    ],
    python_requires='>=3.5',
    license='BSD3',
    packages=find_packages(),
    install_requires=[
    ],
    entry_points={
    },
)
