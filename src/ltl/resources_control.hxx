/*
Lightweight Automated Planning Toolkit
Copyright (C) 2012
Miquel Ramirez <miquel.ramirez@rmit.edu.au>
Nir Lipovetzky <nirlipo@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __RESOURCES_CONTROL__
#define __RESOURCES_CONTROL__

#include <sys/time.h>
#include <unistd.h>
#include <iostream>
#include <iomanip>

namespace aptk {
    #ifdef WIN32

        #include <sys/time.h>			/* for struct timeval */
        #include <limits.h>				/* for CLK_TCK */

        #define RUSAGE_SELF		0

        struct rusage
        {
            struct timeval ru_utime;	/* user time used */
            struct timeval ru_stime;	/* system time used */
        };

        int getrusage(int who, struct rusage *rusage);
    #endif

    double time_used();

    template <typename Stream>
    void report_interval( double t0, double t1, Stream& os );

    #ifndef WIN32
        double mem_used();
    #endif

};

#endif // Resources_Control.hxx
