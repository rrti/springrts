/*
        header for pr-downloader
*/

#ifndef PR_DOWNLOADER_H
#define PR_DOWNLOADER_H

#include "Downloader/DownloadEnum.h"

#define NAME_LEN 1024
struct downloadInfo
{
	char filename[NAME_LEN];
	bool validated;
	int speed;
	DownloadEnum::Category cat;
};
/**
        downloads all downloads that where added with @DownloadAdd
        clears search results
*/
static int DownloadStart() { return 0; }

/**
        adds a download by url without searching
*/
static int DownloadAddByUrl(DownloadEnum::Category cat, const char* filename, const char* url) { return 0; }

/**
        adds a download, see @DownloadSearch & @DownloadGetSearchInfo
*/
static bool DownloadAdd(unsigned int id) { return false; }
/**
* search for name
* calling this will overwrite results from the last call
* @return count of results
* @see downloadSearchGetId
*/
static int DownloadSearch(DownloadEnum::Category category, const char* name) { return 0; }

/**
*	get info about a result / current download
*/
static bool DownloadGetInfo(int id, downloadInfo& info) { return false; }

/**
*	Initialize the lib
*/
static void DownloadInit() {}
/**
*	shut down the lib
*/
static void DownloadShutdown() {}

enum CONFIG {
	CONFIG_FILESYSTEM_WRITEPATH = 1, // const char, sets the output directory
	CONFIG_FETCH_DEPENDS,		 // bool, automaticly fetch depending files
	CONFIG_RAPID_FORCEUPDATE,	// bool, always fetch repo files
};

/**
*	Set an option string
*/
static bool DownloadSetConfig(CONFIG type, const void* value) { return false; }

/**
* returns config value, NULL when failed
*/
static bool DownloadGetConfig(CONFIG type, const void** value) { return false; }

/**
* validate rapid pool
* @param deletebroken files
*/
static bool DownloadRapidValidate(bool deletebroken) { return false; }

/**
* dump contents of a sdp
*/
static bool DownloadDumpSDP(const char* path) { return false; }

/**
* validate sdp files
*/
static bool ValidateSDP(const char* path) { return false; }

/**
* control printing to stdout
*/
static void DownloadDisableLogging(bool disableLogging) {}

typedef void (*IDownloaderProcessUpdateListener)(int done, int size);

static void SetDownloadListener(IDownloaderProcessUpdateListener listener) {}

/*
 * Calculate hash and return it in base64 format.
 * Accepted values for type are:
 *   0 - md5
*/
static char* CalcHash(const char* str, int size, int type) { return nullptr; }

/**
* abort all downloads - must be called before shutting down,
* all downloads must return before calling shutdown
*/
static void SetAbortDownloads(bool value) {}

#endif

