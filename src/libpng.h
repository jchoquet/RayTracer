#ifndef SRC_LIBPNG_H_
#define SRC_LIBPNG_H_

#include "Image.h"

/**
 * \brief Sauvegarde d'une #Image dans un fichier .png.
 * \param bitmap : Image à sauvegarder.
 * \param path : Chemin où sauvegarder l'Image.
 * \return 0 en cas de succès.
 */
int save_png_to_file (Image * bitmap, const char *path);

#endif /* SRC_LIBPNG_H_ */
