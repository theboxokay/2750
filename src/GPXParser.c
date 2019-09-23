#include <stdio.h>
#include <GPXParser.h>
//A1

/* Public API - main */

/** Function to create an GPX object based on the contents of an GPX file.
 *@pre File name cannot be an empty string or NULL.
       File represented by this name must exist and must be readable.
 *@post Either:
        A valid GPXdoc has been created and its address was returned
		or 
		An error occurred, and NULL was returned
 *@return the pointer to the new struct or NULL
 *@param fileName - a string containing the name of the GPX file
**/

static void
print_element_names(xmlNode *a_node)
{
    xmlNode *cur_node = NULL;

    for (cur_node = a_node; cur_node != NULL; cur_node = cur_node->next)
    {
        if (cur_node->type == XML_ELEMENT_NODE)
        {
            printf("node type: Element, name: %s\n", cur_node->name);
        }

        // if (cur_node->content != NULL ){
        //     printf("  content: %s\n", cur_node->content);
        // }

        xmlAttr *attr;
        for (attr = cur_node->properties; attr != NULL; attr = attr->next)
        {
            xmlNode *value = attr->children;
            char *attrName = (char *)attr->name;
            char *cont = (char *)(value->content);
            printf("\tattribute name: %s, attribute value = %s\n", attrName, cont);
        }

        print_element_names(cur_node->children);
    }
}

GPXdoc *createGPXdoc(char *fileName)
{
    if (fileName == NULL)
    {
        printf("error: filename cannot be NULL\n");
        return NULL;
    }
    if (strcmp(fileName, "") == 0)
    {
        printf("error: filename connt be an empty string\n");
        return NULL;
    }

    xmlDoc *doc = NULL;
    xmlNode *root_element = NULL;

    doc = xmlReadFile(fileName, NULL, 0);

    if (doc == NULL)
    {
        printf("error: could not parse file %s\n", fileName);
        return NULL;
    }

    root_element = xmlDocGetRootElement(doc);

    if (root_element == NULL)
    {
        printf("error: failed to parse root element\n");
    }

    print_element_names(root_element);

    xmlFreeDoc(doc);

    xmlCleanupParser();

    return NULL;
}

/** Function to create a string representation of an GPX object.
 *@pre GPX object exists, is not null, and is valid
 *@post GPX has not been modified in any way, and a string representing the GPX contents has been created
 *@return a string contaning a humanly readable representation of an GPX object
 *@param obj - a pointer to an GPX struct
**/
char *GPXdocToString(GPXdoc *doc)
{
}

/** Function to delete doc content and free all the memory.
 *@pre GPX object exists, is not null, and has not been freed
 *@post GPX object had been freed
 *@return none
 *@param obj - a pointer to an GPX struct
**/
void deleteGPXdoc(GPXdoc *doc)
{
}

/* For the five "get..." functions below, return the count of specified entities from the file.  They all share the same format, 
    and only differ in what they have to count.
 
 *@pre GPX object exists, is not null, and has not been freed
 *@post GPX object has not been modified in any way
 *@return the number of entities in the object
 *@param obj - a pointer to an GPXdoc struct
 */

//http://www.trackreport.net
//Routes, tracks, and wayppoints must be stored in the same order as they appera in the file

//Number of waypoints in the GPX file - i.e. objects in the waypoint list
int getNumWaypoints(const GPXdoc *doc);

//Number of routes in the GPX file
int getNumRoutes(const GPXdoc *doc);

//Number of tracks in the GPX file
int getNumTracks(const GPXdoc *doc);

//Total number of segments in all tracks in the document
int getNumSegments(const GPXdoc *doc);

//Total number of attributes in the document
int getNumAttributes(const GPXdoc *doc);

// Function that returns a waypoint with the given name.  If more than one exists, return the first one.
Waypoint *getWaypoint(const GPXdoc *doc, char *name);
// Function that returns a track with the given name.  If more than one exists, return the first one.
Track *getTrack(const GPXdoc *doc, char *name);
// Function that returns a route with the given name.  If more than one exists, return the first one.
Route *getRoute(const GPXdoc *doc, char *name);

/* ******************************* List helper functions  - MUST be implemented *************************** */

void deleteAttribute(void *data);
char *attributeToString(void *data);
int compareAttributes(const void *first, const void *second);

void deleteWaypoint(void *data);
char *waypointToString(void *data);
int compareWaypoints(const void *first, const void *second);

void deleteRoute(void *data);
char *routeToString(void *data);
int compareRoutes(const void *first, const void *second);

void deleteTrackSegment(void *data);
char *trackSegmentToString(void *data);
int compareTrackSegments(const void *first, const void *second);

void deleteTrack(void *data);
char *trackToString(void *data);
int compareTracks(const void *first, const void *second);