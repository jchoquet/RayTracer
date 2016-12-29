#ifndef SCENE_H_
#define SCENE_H_

#include <vector>
#include <string>
#include "Camera.h"
#include "Shape.h"
#include "Vector3f.h"

/** \class Scene
 * \brief Classe qui permet de créer une scène.
 * \details La scène comprend une caméra (cf #Camera), des objets (cf #Shape) et une source de lumière.
 */
class Scene {
public:
    /**
    * \brief Constructeur par défaut.
    * \details Initialise les vecteurs de la Camera et les coordonnées de la source de lumière à 0.
    * Ue sphère est ajoutée à la scène et stockée dans shapes_. Celle-ci est orange (255,127,0), mat (0) et de rayon 50 pixels.
    * Elle est positionnée aux cordonnées (500,0,0).
    */
	Scene();

    /**
    * \brief Constructeur.
    * \details Créé une scène à partir des données passées en argument.
    * \param camera : Valeur initiale pour la caméra camera_.
    * \param shapes : Tableau d'objet initial pour le tableau shapes_.
    * \param nb_shape : Nombre d'objet contenu initialement dans la scène (nb_shapes_).
    * \param source : Position initiale de la source de lumière contenue dans source_.
    * \param width : Valeur initiale de la largeur de l'image width_.
    * \param height : Valeur initiale de la hauteur de l'image height_.
    */
	Scene(Camera& camera, std::vector<Shape*> shapes, int nb_shape, Vector3f& source);

	/**
    * \brief Destructeur.
    * \details Supprime les objets stockés dans shapes_ puis réduit sa capacité à 0.
    */
	~Scene();

    /**
    * \brief Accesseur pour la #Camera camera_.
    * \return Une référence constante vers la caméra de la scène.
    */
	const Camera& getCamera() const {
		return camera_;
	}

    /**
    * \brief Mutateur pour la #Camera camera_.
    * \param camera : Nouvelle valeur pour la caméra de la scène camera_.
    */
	void setCamera(const Camera& camera) {
		camera_ = camera;
	}

	/**
    * \brief Accesseur pour le nombre d'objets nb_shape_.
    * \return Un \e int contenant le nombre d'objets présents sur la scène.
    */
	int getNbShape() const {
		return nb_shape_;
	}

    /**
    * \brief Mutateur pour le nombre d'objets nb_shape_.
    * \param nbShape : Nouveau nombre d'objets présents sur la scène.
    */
	void setNbShape(int nbShape) {
		nb_shape_ = nbShape;
	}

	/**
    * \brief Accesseur pour le vecteur shapes_.
    * \return Une référence constante vers le vecteur contenant les objets stockés sur la scène shapes_.
    */
	const std::vector<Shape*>& getShapes() const {
		return shapes_;
	}

	/**
    * \brief Accesseur pour le vecteur source_.
    * \return Une référence constante vers la valeur du vecteur contenant la position de la source de lumière.
    */
	const Vector3f& getSource() const {
		return source_;
	}

	/**
    * \brief Mutateur pour le vecteur source_.
    * \param source : Nouvelle valeur pour le vecteur source_ contenant la position de la source de lumière.
    */
	void setSource(const Vector3f& source) {
		source_ = source;
	}

    /**
    * \brief Rendu de la scène.
    * \details Crée et sauvegarde l'image correspondant à la scène. La taille et le nom du fichier sont spécifiés.
    * \param width : Largeur de l'image souhaitée.
    * \param height : Longueur de l'image souhaitée.
    * \param name : Nom du fichier final.
    * \param x_image :
    * \param y_topleft_image :
    * \param z_topleft_image :
    */
	void render(int width, int height, char* name, int x_image, int y_topleft_image, int z_topleft_image);

private:
	Camera camera_; /*!< Camera représentant la caméra de la scène*/
	std::vector<Shape*> shapes_; /*!< Vecteur contenant les différents objets*/
	Vector3f source_; /*!< Vecteur 3D de flottant représentant la position de la source de lumière*/
	int nb_shape_; /*!< Entier contenant le nombre d'objets présents sur la scène*/
};

#endif /* SCENE_H_ */
