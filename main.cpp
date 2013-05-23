#include <GL/glut.h> 
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "glm.h"

double posisiX=-5,posisiY=-4.6,posisiZ=17, rotateX=90;


GLMmodel* model1 = NULL;
GLMmodel* model2 = NULL;
GLMmodel* model3 = NULL;
GLMmodel* model4 = NULL;

int posisi=0;
void grid3d(int baris, int kolom, int z) {

    int i;

    int kiri  = -kolom / 2; //batas kiri x
    int kanan = kolom / 2; //batas kanan x
    int bawah = -baris / 2; //batas bawah y
    int atas  = baris / 2; //batas atas y

    glBegin(GL_LINES);
    glLineWidth(1);

    //Baris digambar dari atas ke bawah
    for (i = 0; i < baris + 1; i++) {
        glVertex3f(kiri, baris / 2 - i, z);
        glVertex3f(kanan, baris / 2 - i, z);
    }

    //Kolom digambar dari kanan ke kiri
    for (i = 0; i < kolom + 1; i++) {
        glVertex3f(kolom / 2 - i, bawah, z);
        glVertex3f(kolom / 2 - i, atas, z);
    }

    glLineWidth(3);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(kiri, 0, z);
    glVertex3f(kanan, 0, z);
    glVertex3f(0, bawah, z);
    glVertex3f(0, atas, z);

    glEnd();
    
}
void awan()
{
 glEnable(GL_COLOR_MATERIAL);
 glPushMatrix();
 glColor3f(1, 1, 1);
 glutSolidSphere(10, 50, 50);
 glPopMatrix();
 glPushMatrix();
 glTranslatef(10,0,1);
 glutSolidSphere(5, 50, 50);
 glPopMatrix();
 glPushMatrix();
 glTranslatef(-2,6,-2);
 glutSolidSphere(7, 50, 50);
 glPopMatrix();
 glPushMatrix();
 glTranslatef(-10,-3,0);
 glutSolidSphere(7, 50, 50);
 glPopMatrix();
 glPushMatrix();
 glTranslatef(6,-2,2);
 glutSolidSphere(7, 50, 50);
 glPopMatrix();
 glDisable(GL_COLOR_MATERIAL);
}
void rumput()
{
 //Rumput
 glEnable(GL_COLOR_MATERIAL);
 glPushMatrix();
 glRotatef(90,0,0,1);
 glTranslatef(-6.6,-1.5,0);
 glColor3f(0,1,0.2);
 glScalef(0.11,10,10);
 glutSolidCube(4.);
 glPopMatrix();
 glDisable(GL_COLOR_MATERIAL);
 
 //tanah
 glEnable(GL_COLOR_MATERIAL);
 glPushMatrix();
 glRotatef(90,0,0,1);
 glTranslatef(-6.6,-1.5,0);
 glColor3f(0.7,0.3,0);
 glScalef(0.04,50,50);
 glutSolidCube(4.);
 glPopMatrix();
 glDisable(GL_COLOR_MATERIAL);
}
void pager()
{
 //Pager      
              glEnable(GL_COLOR_MATERIAL);
              glPushMatrix();
              glTranslatef(7,-5.5,13);
              glColor3f(0.3,0.2,0);
              glScalef(15.75,0.5,0.75);
              glutSolidCube(1);
              glPopMatrix();
              glDisable(GL_COLOR_MATERIAL);
              
              glPushMatrix();
              glTranslatef(7,-0.5,13);
              glColor3f(1,0,0);
              glScalef(15.75,0.5,0.75);
              glutSolidCube(1);
              glPopMatrix();

 for (float dep=0.5;dep<13;dep+=2)
       {      
              glEnable(GL_COLOR_MATERIAL);
              glPushMatrix();
              glTranslatef(dep,-3,13);
              glColor3f(0.7,0.3,0);
              glScalef(1,7,0.5);
              glutSolidCube(1);
              glPopMatrix();
              glDisable(GL_COLOR_MATERIAL);
       }

 //pager depan kiri
              glPushMatrix();
              glEnable(GL_COLOR_MATERIAL);
              glTranslatef(-8,-5.5,13);
              glColor3f(0.3,0.2,0);
              glScalef(9.5,0.5,0.75);
              glutSolidCube(1);
              glDisable(GL_COLOR_MATERIAL);
              glPopMatrix();
              
              glPushMatrix();
              glEnable(GL_COLOR_MATERIAL);
              glTranslatef(-8,-0.5,13);
              glColor3f(1,0,0);
              glScalef(9.5,0.5,0.75);
              glutSolidCube(1);
              glDisable(GL_COLOR_MATERIAL);
              glPopMatrix();

  for (float dep2=-4;dep2>-12;dep2-=2)
       {
              glPushMatrix();
              glEnable(GL_COLOR_MATERIAL);
              glTranslatef(dep2,-3,13);
              glColor3f(0.7,0.3,0);
              glScalef(1,7,0.5);
              glutSolidCube(1);
              glDisable(GL_COLOR_MATERIAL);
              glPopMatrix();
       }

  //pagar belakang
              glPushMatrix();
              glEnable(GL_COLOR_MATERIAL);
              glTranslatef(1.2,-5.5,-13);
              glColor3f(0.3,0.2,0);
              glScalef(27.8,0.5,0.75);
              glutSolidCube(1);
              glDisable(GL_COLOR_MATERIAL);
              glPopMatrix();
              
              glPushMatrix();
              glEnable(GL_COLOR_MATERIAL);
              glTranslatef(1.2,-0.5,-13);
              glColor3f(1,0,0);
              glScalef(27.8,0.5,0.75);
              glutSolidCube(1);
              glDisable(GL_COLOR_MATERIAL);
              glPopMatrix();

  for (float dep=-10;dep<13;dep+=2)
       {
              glPushMatrix();
              glEnable(GL_COLOR_MATERIAL);
              glTranslatef(dep,-3,-13);
              glColor3f(0.7,0.3,0);
              glScalef(1,7,0.5);
              glutSolidCube(1);
              glDisable(GL_COLOR_MATERIAL);
              glPopMatrix();
       }

 //pagar samping kanan
              glPushMatrix();
              glEnable(GL_COLOR_MATERIAL);
              glTranslatef(14.2,-5.5,0);
              glColor3f(0.3,0.2,0);
              glScalef(0.75,0.5,28);
              glutSolidCube(1);
              glDisable(GL_COLOR_MATERIAL);
              glPopMatrix();
              
              glPushMatrix();
              glEnable(GL_COLOR_MATERIAL);
              glTranslatef(14.2,-0.5,0);
              glColor3f(1,0,0);
              glScalef(0.75,0.5,28);
              glutSolidCube(1);
              glDisable(GL_COLOR_MATERIAL);
              glPopMatrix();

  for (float samp=-13;samp<15;samp+=2)
       {
              glPushMatrix();
              glEnable(GL_COLOR_MATERIAL);
              glTranslatef(14.2,-3,samp);
              glColor3f(0.7,0.3,0);
              glScalef(0.5,7,1);
              glutSolidCube(1);
              glDisable(GL_COLOR_MATERIAL);
              glPopMatrix();
  }
//pagar samping
              glPushMatrix();
              glEnable(GL_COLOR_MATERIAL);
              glTranslatef(-12,-5.5,0);
              glColor3f(0.3,0.2,0);
              glScalef(0.75,0.5,28);
              glutSolidCube(1);
              glDisable(GL_COLOR_MATERIAL);
              glPopMatrix();
              
              glPushMatrix();
              glEnable(GL_COLOR_MATERIAL);
              glTranslatef(-12,-0.5,0);
              glColor3f(1,0,0);
              glScalef(0.75,0.5,28);
              glutSolidCube(1);
              glDisable(GL_COLOR_MATERIAL);
              glPopMatrix();

  for (float samp=-13;samp<15;samp+=2)
       {
              glPushMatrix();
              glEnable(GL_COLOR_MATERIAL);
              glTranslatef(-12,-3,samp);
              glColor3f(0.7,0.3,0);
              glScalef(0.5,7,1);
              glutSolidCube(1);
              glDisable(GL_COLOR_MATERIAL);
              glPopMatrix();
                }
}
void matahari(){

//matahari
 glPushMatrix();
 glEnable(GL_COLOR_MATERIAL);
 //glTranslatef(10,10,-10);
 glColor3f(1,1,0);
 //glScalef(1.5,1,2);
 glutSolidSphere(2.0,100,10);
 glDisable(GL_COLOR_MATERIAL);
 glPopMatrix();
}

void sapi()
{glEnable(GL_COLOR_MATERIAL);
     glPushMatrix();
     glTranslatef(1,-4,0);
     glRotatef(90,0,1,0);
     glScalef(2,2.5,2);

     glmDraw(model1, GLM_SMOOTH | GLM_MATERIAL|GLM_TEXTURE);  
     glPopMatrix();
     glDisable(GL_COLOR_MATERIAL);
     //sapi2
     glPushMatrix();
     glTranslatef(-1,-4,6);
     glRotatef(90,0,1,0);
     glScalef(2,2.5,2);
     glColor3f(0.6,1,1);
     glmDraw(model1, GLM_SMOOTH | GLM_MATERIAL|GLM_TEXTURE);  
     glPopMatrix();
     //sapi3
         glPushMatrix();
     glTranslatef(7,-4,4);
     glRotatef(90,0,1,0);
     glScalef(3,3,3);
     glColor3f(1,0.5,0.3);
     glmDraw(model1, GLM_SMOOTH | GLM_MATERIAL|GLM_TEXTURE);  
     glPopMatrix();
     //sapi4
         glPushMatrix();
     glTranslatef(-5,-4, 0);
     glRotatef(90,0,1,0);
     glScalef(2,2.5,2);
    
     glmDraw(model1, GLM_SMOOTH | GLM_MATERIAL|GLM_TEXTURE);  
     glPopMatrix();
 
 
 }
 
 void dog()
 
 { 
     glmDraw(model2, GLM_SMOOTH | GLM_MATERIAL|GLM_TEXTURE);   
  }

void birds()
 { glEnable(GL_COLOR_MATERIAL);
      glPushMatrix();
      
   
     glTranslatef(19,11,-4);
     glRotatef(90,0,1,0);
     glScalef(1,1,1);
     glmDraw(model4, GLM_SMOOTH | GLM_MATERIAL|GLM_TEXTURE); 
     
  
     glPopMatrix();
  glDisable(GL_COLOR_MATERIAL);
  }
    
  void pig()
  {
        glPushMatrix();
         glEnable(GL_COLOR_MATERIAL);
     glTranslatef(1,-4,-3);
     glRotatef(90,0,1,0);
     glScalef(2,2.5,2);//
     //glColor3f(1,1,1);
     glmDraw(model3,GLM_SMOOTH | GLM_MATERIAL|GLM_TEXTURE);
     glDisable(GL_COLOR_MATERIAL);  
     glPopMatrix();
     //sapi2
     glPushMatrix();
      glEnable(GL_COLOR_MATERIAL);
     glTranslatef(-1,-4,-5);
     glRotatef(90,0,1,0);
     glScalef(2,2.5,2);
     //glColor3f(0.6,1,1);
     glmDraw(model3, GLM_SMOOTH | GLM_MATERIAL|GLM_TEXTURE);
     glDisable(GL_COLOR_MATERIAL);  
     glPopMatrix();
     //sapi3
         glPushMatrix();
          glEnable(GL_COLOR_MATERIAL);
     glTranslatef(7,-4,-6);
     glRotatef(90,0,1,0);
     glScalef(3,3,3);
     //glColor3f(1,0.5,0.3);
     glmDraw(model3, GLM_SMOOTH | GLM_MATERIAL|GLM_TEXTURE);
     glDisable(GL_COLOR_MATERIAL);  
     glPopMatrix();
     //sapi4
         glPushMatrix();
          glEnable(GL_COLOR_MATERIAL);
     glTranslatef(-5,-4, -3);
     glRotatef(90,0,1,0);
     glScalef(2,2.5,2);
    
     glmDraw(model3, GLM_SMOOTH | GLM_MATERIAL|GLM_TEXTURE);  
     glDisable(GL_COLOR_MATERIAL);
     glPopMatrix();
 
   }
void pohon()
{
//batang
GLUquadricObj *pObj;
pObj =gluNewQuadric();
gluQuadricNormals(pObj, GLU_SMOOTH);

glEnable(GL_COLOR_MATERIAL);
glPushMatrix();
glColor3f(0.7,0.3,0);
glRotatef(270,1,0,0);
gluCylinder(pObj, 1, 0.7, 10, 20, 15);
glPopMatrix();
glDisable(GL_COLOR_MATERIAL);

//ranting

glPushMatrix();
glColor3ub(104,70,14);
glTranslatef(0,7,0);
glRotatef(330,1,0,0);
gluCylinder(pObj, 0.6, 0.1, 7, 25, 25);
glPopMatrix();
 
//daun
glEnable(GL_COLOR_MATERIAL);
glPushMatrix();
glColor3f(0,1,0.3);
glScaled(4, 3, 5);
glTranslatef(0,4.7,0.4);
glutSolidDodecahedron();
glPopMatrix();
glDisable(GL_COLOR_MATERIAL);
}        
int xRot = 0, yRot = 0;
int ztef=0;
void pressKey(int key, int x, int y) 
{ 
    switch (key) 
    { 
         case GLUT_KEY_LEFT : yRot -= 1;break; 
         case GLUT_KEY_RIGHT : yRot += 1;break; 
         case GLUT_KEY_UP : ztef += 1;break;
         case GLUT_KEY_DOWN : ztef -= 1;break;
     } 
         glutPostRedisplay(); 
}

float speed;
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
        
    glPushMatrix();
    glRotatef(xRot, 1.0,0.0,0.0);
    glRotatef(yRot, 0.0,1.0,0.0);
    glTranslatef(0,0,ztef);
  pager();
	rumput();
	sapi();
	pig();
	birds();
	
	
	glPushMatrix();
     glTranslatef(posisiX,posisiY,posisiZ);
     glRotatef(rotateX,0,1,0);
     glScalef(2,2.5,2);
     dog();
	 glPopMatrix();
     
     
	
	glPushMatrix();
	glTranslatef(20,-8,-1);
    pohon();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(10,-8,-31);
    pohon();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-7,-8,-20);
    pohon();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-30,-8,2);
    pohon();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-10,-8,20);
    pohon();
    glPopMatrix();
    glPopMatrix();
    
    
    glPushMatrix();
    glTranslatef(-10,10,-20);
    glTranslatef(-speed*0.001,speed*0.01,0);
	matahari();
	
	glPopMatrix();
    glPushMatrix();
    glTranslatef(-12,50,-30);
    glTranslatef(-speed*0.01,speed*0.01,0);
    awan();
    birds();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(40,50,-50);
    glTranslatef(-speed*0.01,speed*0.01,0);
    awan();
    birds();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-40,40,-40);
    glTranslatef(-speed*0.01,speed*0.01,0);
    awan();
    birds();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(90,40,-40);
    glTranslatef(-speed*0.01,speed*0.01,0);
    awan();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(90,40,-100);
    glTranslatef(-speed*0.1,speed*0.01,speed*0.05);
    awan();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(30,40,-150);
    glTranslatef(-speed*0.1,speed*0.01,speed*0.05);
    awan();
    glPopMatrix();
    
   

    glutSwapBuffers();
    glFlush();
}
void processNormalKeys(unsigned char key, int x, int y) {
  switch(key) {
case 'm':
    posisiX+=1;
    rotateX=90;
    // Kode ASCII tombol ESC
 // Exit kalau ESC ditekan
break;
case 'n':
     glPushMatrix();
     posisiX-=1;
     rotateX=-90;
     dog();
     
     glPopMatrix();
    // Kode ASCII tombol ESC
 // Exit kalau ESC ditekan
break;
case 'b':
     glPushMatrix();
     posisiZ-=1;
    rotateX=-180;
     dog();
     
     glPopMatrix();
      glutSwapBuffers();
    glFlush();
    // Kode ASCII tombol ESC
 // Exit kalau ESC ditekan
break;
case 'v':
     glPushMatrix();
     posisiZ+=1;
     rotateX=0;
     dog();
     
     glPopMatrix();
      glutSwapBuffers();
    glFlush();
    // Kode ASCII tombol ESC
 // Exit kalau ESC ditekan
break;
}
glutPostRedisplay();
}

void cahaya(){

    //lighting code here
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    
    
    float light_ambient[] = { 0.4, 0.4, 0.4, 1 };
   float light_diffuse[] = { 1, 1, 1, 1 }; 
    float light_specular[] = { 1.0, 1.0, 1.0, 1 };
    
    float light_position[] = {12,10, 9, 1 };
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
   
    
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    
    
    glEnable(GL_COLOR_MATERIAL);
    float mat_ambient[] = { 1.0, 1.0, 1.0, 1.0 }; 
    float mat_diffuse[] = { 1.0, 1.0, 1.0, 1.0 }; 
    float mat_specular[] = { 1.0, 1.0, 1.0, 1.0 }; 
    float high_shininess[] = {40.0 }; 
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient); 
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse); glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular); 
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

}


void Timer(int)
{
speed++;
glutPostRedisplay();
glutTimerFunc(10,Timer,0);
}

void init() {
    glClearColor(0, 0.7, 0.9, 1);
     model1 = glmReadOBJ("mod/cartoon_cow.obj");
    glmUnitize(model1);
    glmFacetNormals(model1);
    glmVertexNormals(model1, 90.0);
    model2 = glmReadOBJ("mod/dog.obj");
    glmUnitize(model2);
    glmFacetNormals(model2);
    glmVertexNormals(model2, 90.0);
    
     
    
     model3 = glmReadOBJ("mod/pig.obj");
    glmUnitize(model3);
    glmFacetNormals(model3);
    glmVertexNormals(model3, 90.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    model4 = glmReadOBJ("mod/birds.obj");
    glmUnitize(model4);
    glmFacetNormals(model4);
    glmVertexNormals(model4, 90.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    //glFrustum(-10.0, 10.0, -10.0, 10.0, 4.0, 50.0);
    
    gluPerspective(90, 1, 1, 100); 
    gluLookAt(0, 0, 30, 0, 0, 0, 0.0, 1.0, 0.0);

    glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char * * argv) {
    glutInit( & argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tugas");

    glutDisplayFunc(display);
    glutTimerFunc(0,Timer,0);
    init();
    cahaya();
    glutSpecialFunc(pressKey);
    glutKeyboardFunc(processNormalKeys);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);	
	
    glutMainLoop();

    return 0;
}
