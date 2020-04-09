#pragma once
#include <iostream>
#include <string>
using namespace std;

class Camera {
private:
	char* numar_camera;
	char* tip;
	int id;
	bool libera;
public:
	Camera();
	Camera(const char*,const char*, int,bool);
	Camera(const Camera&);


	void setLibera(bool);
	void setTip(const char*);
	void setNrCam(const char*);
	void setID(int);

	char* getNrCam();
	char* getTip();
	int getID();
	bool getLibera();
	Camera& operator=(const Camera&);
	bool operator==(const Camera&);
	bool operator<(const Camera&);
	~Camera();
	friend ostream& operator<<(ostream& os, Camera c);
	friend istream& operator>>(istream&, Camera&);
};

