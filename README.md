# tmark
Markdown renderer with templates


## Why this Project Exists

This was my situation:
- Create a website with as much source as possible in Markdown.
- Style the site with Tailwind CSS.
- Change the styling of all (or a set of) pages by editing one template.
- Make sure the tool was trustable and reliable.

I could not find anything that matched this. Maybe I didn't look deep enough.


## Building

This is such an early stage of the project that even the command line interface
does not exist. For now you can see the tests running and code coverage. Install
these first:
- GNU GCC
- CMake

To build the project for development/testing:
1. Get a copy of the source code
2. Create a `build` directory inside the project dir
3. Open a Terminal and change to `build`
4. Generate build scripts with `cmake -DCMAKE_BUILD_TYPE=Debug ../src`
5. Build with `cmake --build .`

For a release build, create a `release` dir and use a build type of `Release`.


## Testing

This project aims for Test Driven Development as much as possible. Complete test
coverage (100%) is always the goal. To run tests, first install:
- Catch2

For code coverage, get:
- GNU `gcov`
- Python package `gcovr`

Run tests and get coverage like so:
1. Build the project

2. Open a Terminal to dir `build`

3. Run tests with `./tmark_tests`. See Catch2 docs for ways to produce more
   detailed output. You can also use `./tmark_tests --help` for an overview.

4. Show summary of coverage with `gcovr --root ../ --txt-summary`

5. Create a dir `coverage` inside `build`

6. Generate coverage report in HTML (excluding coverage of test files):

   ```bash
   gcovr --root ../ --exclude ../src/tests \
   --txt-summary --html-details coverage/coverage.htm
   ```

7. If you want the coverage for just the tests separately, do:

   ```bash
   gcovr --root ../ --filter ../src/tests \
   --html-details coverage/covered_tests.htm
   ```

The tests contain checks whose branches can of course never be fully covered.
It is recommended that tests always be excluded from coverage measurement.
Separately measuring coverage inside the test sources can be useful to find
unused code there.


## License

```
tmark - Markdown renderer with templates
Copyright (C) 2025  Sivasankaran K B

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, see <https://www.gnu.org/licenses/>.
```