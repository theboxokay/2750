#include <stdio.h>
#include <GPXParser.h>

int main(int argc, char **argv)
{
    GPXdoc *doc = NULL;

    doc = createGPXdoc("misc/other/Reyn-Rozh_parking(0rt_1trk_1seg_400m).gpx");

    return 0;
}