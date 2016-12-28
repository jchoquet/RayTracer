#ifndef CAMERA_H_
#define CAMERA_H_

#include "Vector3f.h"

/** \class Camera
 * \brief Représente la caméra ou l'oeuil avec lequel on regarde la scène.
 * \details La caméra est déterminée par une position et une direction sous forme de vecteur 3D de flottants (cf #Vector3f).
 */
class Camera {
public:
    /**
    * \brief Constructeur par défaut.
    * \details Initialise les coordonnées des vecteurs position_ et direction_ à 0.
    */
	Camera();

    /**
    * \brief Constructeur.
    * \details Initialise les vecteurs composantes avec ceux passés en argument.
    * \param position : Valeur initiale du vecteur position_.
    * \param direction : Valeur initiale du vecteur direction_.
    */
	Camera(Vector3f position, Vector3f direction);

	/**
    * \brief Destructeur.
    */
	~Camera();

    /**
    * \brief Accesseur pour le vecteur direction_.
    * \return Une référence constante vers la valeur du vecteur de direction.
    */
	const Vector3f& getDirection() const {
		return direction_;
	}

	/**
    * \brief Mutateur pour le vecteur direction_.
    * \param direction : nouvelle valeur pour le vecteur direction_.
    */
	void setDirection(const Vector3f& direction) {
		direction_ = direction;
	}

	/**
    * \brief Accesseur pour le vecteur position_.
    * \return Une référence constante vers la valeur du vecteur de position.
    */
	const Vector3f& getPosition() const {
		return position_;
	}

	/**
    * \brief Mutateur pour le vecteur position_.
    * \param direction : nouvelle valeur pour le vecteur position_.
    */
	void setPosition(const Vector3f& position) {
		position_ = position;
	}

private:
	Vector3f position_; /*!< Vecteur 3D contenant la position de la caméra*/
	Vector3f direction_; /*!< Vecteur 3D contenant la direction de vue de la caméra*/
};

#endif /* CAMERA_H_ */
