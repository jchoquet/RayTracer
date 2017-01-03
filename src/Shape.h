#ifndef SHAPE_H_
#define SHAPE_H_

#include "Material.h"
#include "Ray3f.h"

/** \class Shape
 * \brief Classe abstraite permettant de définir un objet.
 * \details L'objet est défini par le matériel le composant (cf #Material).
 */
class Shape {
public:
    /**
    * \brief Constructeur par défaut.
    * \details Créé un objet fait d'un matériel noir mat.
    */
	Shape();

	/**
    * \brief Constructeur.
    * \details Crée un objet fait du matériel passé en argument.
    * \param  matter Valeur initiale du matériel matter_ composant l'objet.
    */
	Shape(const Material& matter);

	/**
    * \brief Destructeur.
    */
	virtual ~Shape();

	/**
    * \brief Accesseur pour le matériel composant l'objet matter_.
    * \return Une référence constante vers le #Material matter_.
    */
	const Material& getMatter() const {
		return matter_;
	}

	/**
    * \brief Mutateur pour le matériel composant l'objet matter_.
    * \param matter  Nouvelle valeur pour le #Material matter_.
    */
	void setMatter(const Material& matter) {
		matter_ = matter;
	}

	/**
    * \brief Réflection d'un rayon sur l'objet.
    * \param ray  Rayon que l'on veut réfléchir sur l'objet.
    * \return Une référence constante vers le rayon #Ray3f réfléchi par l'objet.
    */
	const Ray3f& reflect(const Ray3f& ray);

	/**
    * \brief Intersection entre l'objet et un rayon.
    * \details Méthode virtuelle.
    */
	virtual bool isHit(Ray3f ray, double* distance,double* px,double* py,double* pz) = 0;

protected:
	Material matter_; /*!< Matériel dont est composé la forme */
};

#endif /* SHAPE_H_ */
