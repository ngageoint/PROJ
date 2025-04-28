#include <stdint.h>
#include <string.h>

#include "embedded_resources.h"

#if USE_SHARP_EMBED

#include "PROJ_DB_SQL_MD5.h"

const unsigned char *pj_get_embedded_proj_db(unsigned int *pnSize) {
    (void)PROJ_DB_SQL_MD5;
    static const unsigned char proj_db[] = {
#embed PROJ_DB
    };
    *pnSize = (unsigned int)sizeof(proj_db);
    return proj_db;
}

#else

#include "file_embed/proj_db.h"
const unsigned char *pj_get_embedded_proj_db(unsigned int *pnSize) {
    *pnSize = proj_db_size;
    return proj_db_data;
}

#endif

// Workaround: Duplicate symbols with two files named embedded_resources.c (file_embed/embedded_resources.h)
// Copy the generated contents inline from the CMake build process

//#include "file_embed/embedded_resources.c"

extern const uint8_t proj_ini_data[];
extern const unsigned proj_ini_size;
extern const uint8_t world_data[];
extern const unsigned world_size;
extern const uint8_t other_extra_data[];
extern const unsigned other_extra_size;
extern const uint8_t nad27_data[];
extern const unsigned nad27_size;
extern const uint8_t GL27_data[];
extern const unsigned GL27_size;
extern const uint8_t nad83_data[];
extern const unsigned nad83_size;
extern const uint8_t nad_lst_data[];
extern const unsigned nad_lst_size;
extern const uint8_t CH_data[];
extern const unsigned CH_size;
extern const uint8_t ITRF2000_data[];
extern const unsigned ITRF2000_size;
extern const uint8_t ITRF2008_data[];
extern const unsigned ITRF2008_size;
extern const uint8_t ITRF2014_data[];
extern const unsigned ITRF2014_size;
extern const uint8_t ITRF2020_data[];
extern const unsigned ITRF2020_size;

const unsigned char *pj_get_embedded_resource(const char* filename, unsigned int *pnSize)
{
    if (strcmp(filename, "proj.ini") == 0)
    {
        *pnSize = proj_ini_size;
        return proj_ini_data;
    }
    if (strcmp(filename, "world") == 0)
    {
        *pnSize = world_size;
        return world_data;
    }
    if (strcmp(filename, "other.extra") == 0)
    {
        *pnSize = other_extra_size;
        return other_extra_data;
    }
    if (strcmp(filename, "nad27") == 0)
    {
        *pnSize = nad27_size;
        return nad27_data;
    }
    if (strcmp(filename, "GL27") == 0)
    {
        *pnSize = GL27_size;
        return GL27_data;
    }
    if (strcmp(filename, "nad83") == 0)
    {
        *pnSize = nad83_size;
        return nad83_data;
    }
    if (strcmp(filename, "nad.lst") == 0)
    {
        *pnSize = nad_lst_size;
        return nad_lst_data;
    }
    if (strcmp(filename, "CH") == 0)
    {
        *pnSize = CH_size;
        return CH_data;
    }
    if (strcmp(filename, "ITRF2000") == 0)
    {
        *pnSize = ITRF2000_size;
        return ITRF2000_data;
    }
    if (strcmp(filename, "ITRF2008") == 0)
    {
        *pnSize = ITRF2008_size;
        return ITRF2008_data;
    }
    if (strcmp(filename, "ITRF2014") == 0)
    {
        *pnSize = ITRF2014_size;
        return ITRF2014_data;
    }
    if (strcmp(filename, "ITRF2020") == 0)
    {
        *pnSize = ITRF2020_size;
        return ITRF2020_data;
    }
    *pnSize = 0;
    return NULL;
}
