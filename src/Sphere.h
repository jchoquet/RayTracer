#ifndef SPHERE_H_
#define SPHERE_H

#include "Shape.h"

/** \class Sphere
 * \brief Classe héritant de #Shape, permet de définir un cube.
 * \details La sphère est définie par son rayon (flottant) et son centre (vecteur 3D cf #Vector3f).
 */
class Sphere : public Shape {
public:
    /**
    * \brief Constructeur par défaut.
    * \details Créé ue sphère faite d'un matériel noir mat et initialise son rayon et les composantes de son vecteur origine à 0.
    */
	Sphere();

	/**
    * \brief Constructeur.
    * \details Crée une sphère définie par l'origine, la rayon et le matériel passés en argument.
    * \param  matter  Valeur initiale du matériel matter_ composant la sphère.
    * \param origin  Valeur initiale du vecteur origin_.
    * \param radius  Valeur initiale du rayon radius_.
    */
	Sphere(const Material& matter, const Vector3f& origin, float radius);

	/**
    * \brief Destructeur.
    */
	~Sphere();

    /**
    * \brief Accesseur pour le vecteur origin_.
    * \return Une référence constante vers la valeur du vecteur d'origine.
    */
	const Vector3f& getOrigin() const {
		return origin_;
	}

	/**
    * \brief Mutateur pour le vecteur origin_.
    * \param origin  Nouvelle valeur pour le vecteur contenant l'origine origin_.
    */
	void setOrigin(const Vector3f& origin) {
		origin_ = origin;
	}

    /**
    * \brief Accesseur pour le rayon radius_.
    * \return Un \e float avec la valeur du rayon radius_.
    */
	float getRadius() const {
		return radius_;
	}

    /**
    * \brief Mutateur pour le rayon radius_.
    * \param radius  Nouvelle valeur pour le rayon radius_.
    */
	void setRadius(float radius) {
		radius_ = radius;
	}

	/**
    * \brief Intersection entre la sphère et un rayon.
    * \details Utilise l'algorithme de Brian Smits. Calcul l'intersection et vérifie qu'elle est à une distance moins élevée que la précédente grâce
    * au paramètre distance. Si les conditions sont respéctées, les coordonnées du point d'intersection seront stockées dans les pointeurs passés en argument.
    * \param ray  Rayon dont on teste l'intersection avec la sphère.
    * \param distance Distance entre le rayon d'origine et le précèdent point d'intersection.
    * \param px  Pointeur vers un double contenant l'abscisse du précédent point d'intersection.
    * \param py  Pointeur vers un double contenant l'ordonnée du précédent point d'intersection.
    * \param pz  Pointeur vers un double contenant la profondeur du précédent point d'intersection.
    * \return true si le rayon intersecte la sphère et que sa distance avec l'origine du rayon et inférieure à celle pointée dans distance, sinon false.
    */
	bool isHit(Ray3f ray, double* distance, double* px, double* py, double* pz);

private:
	Vector3f origin_; /*!< Vecteur 3D contenant l'origine de la sphère (centre)*/
	float radius_; /*!< Flottant contenant le rayon de la sphère */
};

#endif /* SPHERE_H_ */
