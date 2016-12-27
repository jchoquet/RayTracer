#ifndef RAY3F_H_
#define RAY3F_H_

#include "Vector3f.h"

/** \class Ray3f
 * \brief Rayon avec une origine et une direction sous forme de vecteur 3D de flottants (cf #Vector3f).
 */
class Ray3f {
public:
    /**
    * \brief Constructeur par défaut.
    * \details Initialise les coordonnées des vecteurs origine_ et direction_ à 0.
    */
	Ray3f();

    /**
    * \brief Constructeur.
    * \details Initialise les vecteurs composantes avec ceux passés en argument.
    * \param origin : Valeur initiale du vecteur origin_.
    * \param direction : Valeur initiale du vecteur direction_.
    */
	Ray3f(Vector3f origin, Vector3f direction);

	/**
    * \brief Destructeur.
    */
	~Ray3f();

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
    * \brief Accesseur pour le vecteur origin_.
    * \return Une référence constante vers la valeur du vecteur d'origin.
    */
	const Vector3f& getOrigin() const {
		return origin_;
	}

    /**
    * \brief Mutateur pour le vecteur origin_.
    * \param direction : nouvelle valeur pour le vecteur origin_.
    */
	void setOrigin(const Vector3f& origin) {
		origin_ = origin;
	}

private:
	Vector3f origin_; /*!< Vecteur 3D origine*/
	Vector3f direction_; /*!< Vecteur 3D direction*/
};

#endif /* RAY3F_H_ */
