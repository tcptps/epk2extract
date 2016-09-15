#ifndef __HIPKG_H
#define __HIPKG_H
#include "config.h"

#define UPG_HEADER_SIZE 0x90
#define UPG_SIGNATURE_SIZE 0x80 //+10 unknown bytes
#define PKG_SIGNATURE_SIZE 0x30

#define HISENSE_MTK_MAGIC "iMtK8"
#define HISENSE_PAD_MAGIC "iPAd"

struct hipkg {
	char pakName[8];
	uint32_t size;
	uint8_t signature[PKG_SIGNATURE_SIZE];
	char data[];
};

struct hipkg_plat {
	char platform[8];
	uint32_t otaID_len;
	char otaID[];
};

struct hipkg_pad {
	char magic[8];
	uint8_t padding[28];
};

MFILE *is_hisense(const char *pkgfile);
void extract_hisense(MFILE *pkg, struct config_opts_t *config_opts);
#endif