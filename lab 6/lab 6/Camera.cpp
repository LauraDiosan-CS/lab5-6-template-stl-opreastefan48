#include "Camera.h"
#include <string.h>
#include <sstream>
using namespace std;

Camera::Camera() {
	numar_camera = NULL;
	tip = NULL;
	id = 0;
	libera = true;
}

Camera::Camera(const char* numar_camera, const char* tip, int id, bool libera) {
	this->numar_camera = new char[strlen(numar_camera) + 1];
	strcpy_s(this->numar_camera, strlen(numar_camera) + 1, numar_camera);

	this->tip = new char[strlen(tip) + 1];
	strcpy_s(this->tip, strlen(tip) + 1, tip);

	this->id = id;
	this->libera = libera;
	
}

Camera::Camera(const Camera& c) {
	
	this->numar_camera = new char[strlen(c.numar_camera) + 1];
	strcpy_s(this->numar_camera, strlen(c.numar_camera) + 1, c.numar_camera);
	
	this->tip = new char[strlen(c.tip) + 1];
	strcpy_s(this->tip, strlen(c.tip) + 1, c.tip);

	this->id = c.id;
	this->libera = c.libera;

}


int Camera::getID() {
	return id;
}

void Camera::setID(int i) {
	id = i;
}

void Camera::setLibera(bool l) {
	libera = l;
}

char* Camera::getNrCam() {
	return numar_camera;
}
char* Camera::getTip() {
	return tip;
}
bool Camera::getLibera() {
	return libera;
}

void Camera::setNrCam(const char* n) {
	if (numar_camera)
		delete[]numar_camera;
	numar_camera = new char[strlen(n) + 1];
	strcpy_s(numar_camera, strlen(n) + 1, n);

}void Camera::setTip(const char* n) {
	if (tip) 
		delete[]tip;
	tip = new char[strlen(n) + 1];
	strcpy_s(tip, strlen(n) + 1, n);
}


Camera::~Camera() {
	if (numar_camera) 
		delete[]numar_camera;
	if (tip)
		delete[]tip;
	numar_camera = NULL;
	tip = NULL;
	id = -1;
	libera = false;
}

Camera& Camera::operator=(const Camera& c) {
	if (this == &c) 
		return *this; //self-assignment 

	if (numar_camera) 
		delete[] numar_camera;
	if (tip)
		delete[]tip;

	numar_camera = new char[strlen(c.numar_camera) + 1];
	strcpy_s(numar_camera, strlen(c.numar_camera) + 1, c.numar_camera);

	tip = new char[strlen(c.tip) + 1];
	strcpy_s(tip, strlen(c.tip) + 1, c.tip);

	id = c.id;
	libera = c.libera;

	return *this;
}

bool Camera::operator==(const Camera& c) {
	return (strcmp(numar_camera, c.numar_camera) == 0) and (strcmp(tip, c.tip) == 0) and (id == c.id) and (libera == c.libera);
}

bool Camera::operator<(const Camera& c)
{
	return (strcmp(numar_camera, c.numar_camera) < 0);

}

ostream& operator<<(ostream& os, Camera c) {
	os << c.numar_camera << " " << c.tip<<" "<<c.id<<" "<<c.libera << endl;
	return os;
}

istream & operator>>(istream &is, Camera& c)
{
	cout << "Dati numarul camerei: ";
	char* numar_camera = new char[10];
	char* tip= new char[10];

	is >> numar_camera;
	cout << "Dati tipul camerei: ";
	is >> tip;

	cout << "Dati id-ul camerei: ";
	int id;
	cin >> id;
	bool libera;
	cin >> libera;

	c.setLibera(libera);
	c.setNrCam(numar_camera);
	c.setID(id);
	c.setTip(tip);


	delete[] numar_camera;
	delete[] tip;

	return is;
}
