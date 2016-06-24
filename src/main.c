/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 * runso
 *         Copyright (C) 2016  DirectorX
 *
 *         This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 *         the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 *         but WITHOUT ANY WARRANTY; without even the implied warranty of
 *                         MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>


void print_usage() {
    printf("Usage: runso [path]\n");
}

int main(int argc, char *argv[]) {
    void *handle;
    char *error;
    char *shared_object_path = argv[1];

    if (2 > argc) {
        print_usage();
        return EXIT_FAILURE;
    }

    handle = dlopen(shared_object_path, RTLD_NOW);
    if (!handle) {
        return EXIT_FAILURE;
    }

    if ((error = dlerror()) != NULL) {
        fputs(error, stderr);
        return EXIT_FAILURE;
    }

    dlclose(handle);
    return EXIT_SUCCESS;
}
