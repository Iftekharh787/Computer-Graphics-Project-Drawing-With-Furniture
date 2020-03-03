#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<GL/glut.h>



float  rightTranslate, leftTranslate, move_X, move_Y, move_Z, speed,cameraAngle,cameraRadius, cameraHeight, cameraAngleDelta;

int   movePress,checkLeft,checkRight,canDrawAxis, f, roted,  forward;



GLUquadricObj *obj = gluNewQuadric();

void sofaStand()
{
	glColor3f(.6,0,.2);
	gluCylinder(obj, 2, 5, 20, 10, 25);
}
void cushion_Of_Sofa() {

	glPushMatrix(); {
	
			glPushMatrix(); {
						glScalef(.5, .5, .7);
						glTranslatef(0, 0, 110);						

						glPushMatrix(); {      // Base Part
							glColor3f(0	,.5,	.5); 
							glScalef(80, 40, 80);
							glutSolidSphere(1, 25, 25);
						}glPopMatrix();

						glPushMatrix(); {  // Corner Part 1
							glTranslatef(-50, 0, 50);
							glRotatef(-45, 0, 1, 0);
							glColor3f(0	,1	,.6); 
							glScalef(8, 4, 1);
							glPushMatrix(); {
								glTranslatef(0, 0, 80);
								glutSolidSphere(.5, 25, 25);
							}glPopMatrix();
			
							gluCylinder(obj, 5, 0.5, 80, 25, 25);
						}glPopMatrix();

						glPushMatrix(); {  // Corner Part 2
							glTranslatef(50, 0, 50);
							glRotatef(45, 1, 1, 0);
							glColor3f(0,	1,	.6);
							glScalef(8, 4, 1);
							glPushMatrix(); {
								glTranslatef(0, 0, 80);
								glutSolidSphere(.5, 25, 25);
							}glPopMatrix();

							gluCylinder(obj, 5, .5, 80, 25, 25);
						}glPopMatrix();
		
						glPushMatrix(); {  // Corner Part 3
							glTranslatef(-50, 0, -50);
							glRotatef(-135, 0, 1, 0);
							glColor3f(0,	1,	.6);
							glScalef(8, 3, 1);
							glPushMatrix(); {
								glTranslatef(0, 0, 80);
								glutSolidSphere(.5, 25, 25);
							}glPopMatrix();

							gluCylinder(obj, 5, .5, 80, 25, 25);
						}glPopMatrix();

						glPushMatrix(); {   // Corner Part 4
							glTranslatef(50, 0, -50);
							glRotatef(135, 0, 1, 0);
							glColor3f(0,	1,	.6);
							glScalef(8, 4, 1);
							glPushMatrix(); {
								glTranslatef(0, 0, 80);
								glutSolidSphere(.5, 25, 25);
							}glPopMatrix();

							gluCylinder(obj, 5, .5, 80, 25, 25);
						}glPopMatrix();
           }glPopMatrix();
	}glPopMatrix();
}


void smallSofa()
{
	glPushMatrix(); {
		glTranslatef(0, -200, 0);
		glPushMatrix(); {

						glPushMatrix(); {    // Upper Sit
									glTranslatef(-10, -20, 40);								
									glScalef(60, 60, 12);
									glColor3f(1, 1, 1); 
									glutSolidCube(1);

						}glPopMatrix();

						glPushMatrix(); {    // Down Sit
									glTranslatef(-10, -15, 30);
									glScalef(60, 60, 12);
									glColor3f(.2,	.2	,.2);  
									glutSolidCube(1);
						}glPopMatrix();


						glPushMatrix(); {  // Delan Sit
									glTranslatef(-10, 35, 50);
									glRotatef(-20, 1, 0, 0);
									glScalef(56, 6, 60);
									glColor3f(.4, .4, 1);  
									glutSolidCube(1);
						}glPopMatrix();

						glPushMatrix(); {    //  Left Side
									glTranslatef(-40, -5, 20);
									glScalef(6, 80, 100);
									glColor3f(1	,.8	,1);  
									glutSolidCube(1);


						}glPopMatrix();

						glPushMatrix(); {    //  Right Side
							glTranslatef(20, 5, 20);							
							glScalef(6, 80, 100);
							glColor3f(1	,.8	,1);  
							glutSolidCube(1);														
						}glPopMatrix();
		}glPopMatrix();
	}glPopMatrix();
}

void smallSofaSet() {

	glPushMatrix(); {		 // Left Sofa	

					glTranslatef(- 100,310, 0);		 
		            smallSofa();    // Left  Sofa  draw

	            	glPushMatrix(); { // Cushion Set In Left Sofa
							glTranslatef(-5,-220,50);
							glScalef(.3,.3,.3);
							cushion_Of_Sofa();  
	               }glPopMatrix();

    }glPopMatrix();

	glPushMatrix(); { // Right Sofa 

					glTranslatef(0, 300, 0);		
					smallSofa();    // Right Sofa Draw

					glPushMatrix(); {  // Cushion Set In Right Sofa

							glTranslatef(-5,-200,40);
							glScalef(.3,.3,.3);
							cushion_Of_Sofa();

				  }glPopMatrix();
	}glPopMatrix();
}


void bigSofaWithRightSide()
{

	glPushMatrix(); {

		glTranslatef(100, -100, 50);
	
		glPushMatrix(); {

						glPushMatrix(); {    // Sofa Sit
							glTranslatef(0, 7, 0);
							glScalef(40, 140, 12);
							glColor3f(1, 1, 1);  
							glutSolidCube(1);
						}glPopMatrix();

						glPushMatrix(); {    //  Forward Side
							glTranslatef(0, -70, 0);
							glPushMatrix();{ // Leg
										 glTranslatef(-15, 150, -40);
										 sofaStand();
							}glPopMatrix();
							glScalef(50, 10, 50);
							glColor3f(1	,.8	,1); 
							glutSolidCube(1);
						}glPopMatrix();

						glPushMatrix(); {    //  Right Side
							glTranslatef(20, 10, 0);
							glPushMatrix();{  // Leg
                                 glTranslatef(-42, -80, -40);
								 sofaStand();
							}glPopMatrix();
						
							glScalef(10, 145, 50);
							glColor3f(1	,.8	,1);   
							glutSolidCube(1);
						}glPopMatrix();

						glPushMatrix(); {  // Back side Aganist  Forward Wall
							glTranslatef(0, 80, 0);
							glPushMatrix();{  // Leg
                                 glTranslatef(23, -80, -40);
								 sofaStand();
							}glPopMatrix();
							glScalef(36, 6, 50);
							glColor3f(1	,.8	,1);   
							glutSolidCube(1);
						}glPopMatrix();


		}glPopMatrix();

		glPushMatrix(); {  // Big Sofa Cushion
					glTranslatef(5,60,0);
					glRotatef(180,0,0,1);
					glScalef(.4,.4,.3);
					cushion_Of_Sofa();
		}glPopMatrix();
	}glPopMatrix();

}



void lamp_With_Stand()
{


	glPushMatrix(); {   
	glTranslated(-150, 10, 0);

		glPushMatrix(); {
								glPushMatrix(); {  // Round Base

											glTranslatef(0, 0, 69);
											glScalef(30,30,4);
											glColor3f(.6,.2,0);
											glutSolidSphere(1,10,10);
					
								}glPopMatrix();

								glPushMatrix(); {      // Lamp Head
											glTranslatef(0, 0, 150);
											glColor3f(.4,	.4	,.6);
											gluCylinder(obj, 20, 10, 30, 20, 20);
		                       }glPopMatrix();

								glPushMatrix(); {//leg Back left Against Forward Wall

											glTranslatef(-5, -22, 20);
											glScalef(3, 3, 100);
											glColor3f(.6, .2, 0);
											glutSolidCube(1);

								}glPopMatrix();


								glPushMatrix(); {//leg Back right  Against Forward Wall
											glTranslatef(5, -22, 20);
											glScalef(3, 3, 100);
											glColor3f(.6, .2, 0);
											glutSolidCube(1);
								}glPopMatrix();


								glPushMatrix(); {//leg Forward left  Against Forward Wall
											glTranslatef(-5, 22, 20);
											glScalef(3, 3, 100);
											glColor3f(.6, .2, 0);
											glutSolidCube(1);
								}glPopMatrix();


								glPushMatrix(); {//leg Forward right  Against Forward Wall
											glTranslatef(5, 22, 20);
											glScalef(3, 3, 100);
											glColor3f(.6, .2, 0);
											glutSolidCube(1);
								}glPopMatrix();
			}glPopMatrix();

			glPushMatrix(); {      // Lamp Strick
								glTranslatef(0, 0, 65);
								glColor3f(1,	.31,	.31);
								gluCylinder(obj, 2, 1, 100, 20, 20);
								glPushMatrix(); {   // LAmp Strick Middle Component
									        glTranslatef(0, 0, 50);
											glColor3f(.2	,.4,	1);
											gluCylinder(obj, 3, 2, 10, 20, 20);
								}glPopMatrix();

								glPushMatrix(); {  // Lamp Strick Base 
											glColor3f(.2	,.4,	0);
											glutSolidCone(10,20,10,10);
								}glPopMatrix();
			}glPopMatrix();

		   


	}glPopMatrix();

}


void fire_Place()
{




	glPushMatrix(); {  
						glPushMatrix(); { // Inside Part 
									glTranslatef(5, 0, 60);
									glScalef(1, 75, 100);
									glColor3f(.4,	.2	,0);
									glutSolidCube(1);
						}glPopMatrix();
		
		
						glPushMatrix(); {  // Upper Base
								glTranslatef(10, 0, 110);
								glScalef(20, 75, 12);
								glColor3f(1,1,1);
								glutSolidCube(1);
					  }glPopMatrix();

						glPushMatrix(); {    // Back Leg
								glTranslatef(10, -35, 60);
								glScalef(12, 6, 100);
								glColor3f(1, 1, 1); 
								glutSolidCube(1);
						}glPopMatrix();


						glPushMatrix(); {       // Front  Leg
								glTranslatef(10, 35, 60);
								glScalef(12, 6, 100);
								glColor3f(1, 1, 1); 
								glutSolidCube(1);
						}glPopMatrix();

	}glPopMatrix();


}


void center_Leg()
{
		glPushMatrix(); {
					glScalef(2, 2, 6);
					glColor3f(.5,	0,	0);
					gluCylinder(obj, .5, 2, 3, 10, 10);
		}glPopMatrix();
}
void center_Object() {  


	glPushMatrix(); {
	glTranslatef(-30, -160, 10);

			glPushMatrix(); {// Base 
						glPushMatrix(); {
									glTranslatef(0, 0, 25);
									glScalef(40, 80, 10);
									glColor3f(.4,	.2,	0);
									glutSolidCube(1);
						}glPopMatrix();

						glPushMatrix(); {  // Leg Left 1

		     				 glTranslatef(-15, -35, 0);	
							 center_Leg();

						}glPopMatrix();

						glPushMatrix(); {// Leg Right 1

								glTranslatef(15, -35, 0);			
								center_Leg();

						}glPopMatrix();

						glPushMatrix(); {// Leg  Left 2

							glTranslatef(-16, 35, 0);			
							center_Leg();

						}glPopMatrix();

						glPushMatrix(); {// Leg  Right 2nd 

							glTranslatef(16, 35, 0);		
							center_Leg();

						}glPopMatrix();


		}glPopMatrix();
	}glPopMatrix();

}


void mirror_On_The_Wall_Square() { 

	glPushMatrix(); {

		glPushMatrix(); {    // Inside Mirror
			glColor3f(.58, .58, .58); 
			glScalef(6, 30, 50);
			glutSolidCube(1);
		}glPopMatrix();

		glPushMatrix(); {    // Outside Mirror 
			glColor3f(.8,	0,	0); 
			glScalef(6, 35, 60);
			glutSolidCube(1);
		}glPopMatrix();

	}glPopMatrix();

}


void circleForRoundMirror(float cx, float cy, float r, int num_segments){

	glPushMatrix(); { 

			glBegin(GL_LINE_LOOP);

			for (int ii = 0; ii < num_segments; ii++){

				float theta = 2.0f * 3.14159f * float(ii) / float(num_segments); 
				float x = r * cosf(theta);	
				float y = r * sinf(theta);	
				glVertex2f(cx, cy);	
				glVertex2f(x + cx, y+cy);	
			}
			glEnd();
	}glPopMatrix();
}
void mirror_On_The_Wall_Round()
{
	   glRotatef(-180, 1, 0, 1);
		glPushMatrix(); {    // Inside Mirror
					glColor3f(.58, .58, .58);  // Silver
					glScalef(8, 8, 2);
					glutSolidSphere(1, 20, 20);
		}glPopMatrix();

		glPushMatrix(); {  // Outside Mirror
					glTranslatef(0, 0, .5);
					glColor3f(.4,0,.2); // Yellow
					glutSolidTorus(1, 9, 20, 20);
		}glPopMatrix();

	
		glPushMatrix(); {      // Loop Outside the  Round Mirror
				glTranslatef(-10, -10, 0);
				glColor3f(1,0,0);
				circleForRoundMirror(10,10,20,40);
		}glPopMatrix();

}


void round_Chair_Left_Right_Delan_CommonPart()
{
			double equ[4];
			equ[0] = 0;
			equ[1] = 0;
			equ[2] = 1;
			equ[3] = 0;
			glClipPlane(GL_CLIP_PLANE0, equ);
}
void ChairUpConnector()
{
	gluCylinder(obj, 1, 1, 10, 20, 2);
}

void ChairBlind1()// Front Legs
{
		glPushMatrix();
				round_Chair_Left_Right_Delan_CommonPart();	
				glTranslatef(0,2,-30);
				glEnable(GL_CLIP_PLANE0);
					 glTranslatef(10,0,0);
					 glRotated(90,1,0,0);
					 glScalef(1,4,2);	
					 glutSolidTorus(1.5,20,10,20);
				glDisable(GL_CLIP_PLANE0);
	    glPopMatrix();
}
void ChairDelan()
{
	glPushMatrix();

	           round_Chair_Left_Right_Delan_CommonPart();

			   glEnable(GL_CLIP_PLANE0);

				glPushMatrix(); {       // Base For Delan
							glTranslatef(0, 3, 10);
							glRotated(90,1,0,0);
							glScalef(13, 30, 5);
							glColor3f(.4,.2,0);	//Yellow
							glutWireSphere(1,20,60);
				}glPopMatrix();
	          glDisable(GL_CLIP_PLANE0);
glPopMatrix();
}
void ChairBlind() // Back Legs 
{
	glPushMatrix();

	round_Chair_Left_Right_Delan_CommonPart();

	        glTranslatef(0,2,-30);
			glEnable(GL_CLIP_PLANE0);

				  glTranslatef(10,-2,0);
				  glRotated(90,1,0,0);
				  glScalef(1,7,4);	

				  glutSolidTorus(1.5,20,2,100);
				
			glDisable(GL_CLIP_PLANE0);
   glPopMatrix();
}

void leftRightHandleCommon()
{
 glPushMatrix();

			double equ[4];
			equ[0] = 0;
			equ[1] = -1;
			equ[2] = 0;
			equ[3] = 0;

			glClipPlane(GL_CLIP_PLANE0, equ);
			glEnable(GL_CLIP_PLANE0);					
			glDisable(GL_CLIP_PLANE0);

 glPopMatrix();
}
void right_Hand_Of_Chair ()
{
 glPushMatrix();
	
		 leftRightHandleCommon();
					 glPushMatrix();
						double equ1[4];
						equ1[0] = 1;
						equ1[1] = 0;
						equ1[2] = 0;
						equ1[3] = 0;

						glClipPlane(GL_CLIP_PLANE1, equ1);
						
						glEnable(GL_CLIP_PLANE1);
							 glScalef(1,2,1);	
							 glutSolidTorus(2,10,10,20);
						glDisable(GL_CLIP_PLANE1);

					 glPopMatrix();
 glPopMatrix();
}
void 	left_Hand_Of_Chair()
{
	 glPushMatrix();

	leftRightHandleCommon();
					 glPushMatrix();

							double equ1[4];
							equ1[0] = -1;
							equ1[1] = 0;
							equ1[2] = 0;
							equ1[3] = 0;

							glClipPlane(GL_CLIP_PLANE1, equ1);
					
							glEnable(GL_CLIP_PLANE1);
								 glScalef(1,2,1);	
								 glutSolidTorus(2,10,10,20);
							glDisable(GL_CLIP_PLANE1);

					 glPopMatrix();
	
   glPopMatrix();
}


void roundChair()
{

	glPushMatrix(); {
		glTranslatef(-130, -280, 20);

		glPushMatrix(); {

			glPushMatrix(); {  // Base Sit

				  glPushMatrix(); { // Up Right Handle
							    glTranslatef(10, -2, 80);
								glPushMatrix(); {
										glColor3f(.6,.2,0);  								
										right_Hand_Of_Chair ();
								}glPopMatrix();
			    	}glPopMatrix();

				    glPushMatrix(); { // Up Left Handle

					glTranslatef(-10, -10, 80);
								glPushMatrix(); {
										glColor3f(.6,.2,0);  //Blue	
										left_Hand_Of_Chair();
								}glPopMatrix();
				   }glPopMatrix();

					glTranslatef(-1, -10, 50);
					glScalef(5, 5, 4);
					glColor3f(.8,	0,	0);   
					glutSolidTorus(2, 2.5, 50, 10);  // Sit Shape

			}glPopMatrix();	

			glPushMatrix(); {       // Base For Delan
					glTranslatef(1, -23, 60);			 		
					ChairDelan();
			}glPopMatrix();

			glPushMatrix(); {//Back legs

					glTranslatef(-10, -25, 0);
					glColor3f(.6,.2,0);		
					ChairBlind();

			}glPopMatrix();


			glPushMatrix(); { //leg back left

				     glTranslatef(-7, 0, 0);
				     glPushMatrix(); {  // Up Left Handle  Stand
					               glTranslatef(-13, -4, 50);
								   glPushMatrix(); {

										glColor3f(.6,.2,0);
										glScalef(1, -2, 3);

										ChairUpConnector();

									}glPopMatrix();

			     	}glPopMatrix();

				   glTranslatef(-11, 0, 0);
				   glColor3f(.6,.2,0);

                   ChairBlind1();

			}glPopMatrix();


			glPushMatrix(); {//leg back right
					glTranslatef(7, 0, 0);
					glPushMatrix(); {  // Up Left Handle  Stand
								    glTranslatef(13, -12, 50);
							     	glPushMatrix(); {
									glColor3f(.6,.2,0);  //Pink	       
									glScalef(1, -2, 3);
									ChairUpConnector();
					}glPopMatrix();

			}glPopMatrix();
		 }glPopMatrix();
	  }glPopMatrix();
	}glPopMatrix();
}
void rightCoverAnimation()
{

	if (movePress==1){
			if (checkRight == 0)
			{
				rightTranslate = rightTranslate + .1;

				if (rightTranslate >= 100)
				{
					checkRight = 1;
				}
			}
			
	}
	else 
	{
		 if (checkRight == 1)
			{
				rightTranslate = rightTranslate - .1;

				if (rightTranslate <= 0)
				{
					checkRight = 0;
				}
			}
	}
}
void leftCoverAnimation()
{

	if (movePress==0){

				if (checkLeft == 1)
				{
					leftTranslate = leftTranslate + .1;

					if (leftTranslate >= 3)
					{
						checkLeft = 0;
					}
				}
				
	}
 else 
	{
		 if (checkLeft == 0)
				{
					leftTranslate = leftTranslate -.1;
					if (leftTranslate <= -100)
					{
						checkLeft= 1;
					}
				}
	}

}

void rightCoverTranslate()
{
			glPushMatrix(); {  //Cover Upper Bar   

						glColor3f(.8,	0,	1); 
						glTranslatef(-75, 0, 300);
						glScalef(500, 2, 150);
						glutSolidCube(1);

			}glPopMatrix();

			glPushMatrix(); {    // Cover Right Part With Forward Wall

						glTranslatef(rightTranslate, 0, 10);


						glColor3f(0	,0,	.4);  

						glScalef(150, 2, 380);
						glutSolidCube(1);

						rightCoverAnimation();
			}glPopMatrix();
}

void leftCoverTranslate () 
{
			glPushMatrix(); {  // Left Cover Part With Forward Wall

						glTranslatef(leftTranslate+45, 0, 10);
						glColor3f(0	,0,	.4); 
						glScalef(154, 2, 380);
						glutSolidCube(1);

						leftCoverAnimation();

			}glPopMatrix();
}

void wallOfBoundary() {   // Wall 


	glPushMatrix(); {

						glTranslatef(-250, 0, 300);  // Left Wall 					

						glScalef(0, 1000, 600);
						glColor3f(.4,	1,	.4);
						glutSolidCube(1);	  

	}glPopMatrix();

	
	glPushMatrix(); {   // Forward Wall
						glTranslatef(0, 501, 300);
						glScalef(500, 1, 600);
						glColor3f(.4,	1,	1);
						glutSolidCube(1);
	}glPopMatrix();

					glPushMatrix(); {   // Sub Forward Wall for Window
										glTranslatef(0, 499, 225);
										glScalef(300, .3, 290);
										glColor3f(1, 1, 1);
										glutSolidCube(1);
					 }glPopMatrix();


					 glPushMatrix(); {  //Left Cover
										glTranslatef(-125, 499, 170);
										leftCoverTranslate();

					}glPopMatrix();


					glPushMatrix(); {  // Right Cover
										glTranslatef(75, 499, 170);
										rightCoverTranslate();

					}glPopMatrix();

	glPushMatrix(); {   // Right Wall
						glTranslatef(250, 0, 300);
						glScalef(1, 1000, 600);
						glColor3f(1,	1,	.4);
						glutSolidCube(1);
	}glPopMatrix();

	

	

	glPushMatrix(); {  // Floor Wall
						glTranslatef(0, 0,0);
						glScalef(500, 1000, 0);
						glColor3f(0	,.8	,.4);
						glutSolidCube(1);

	}glPopMatrix();

	  glPushMatrix();{ // Top Wall
				glTranslatef(0,0,600);
				glScalef(500,1000,1);
				glColor3f(.5,.5,.5);
				glutSolidCube(1);
	  }glPopMatrix();


}





void display() {
	//codes for Models, Camera

	//clear the display
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0, 0, 0, 0);	//color black
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		
	glMatrixMode(GL_MODELVIEW);		//specify which matrix is the current matrix

								
	glLoadIdentity();				//replace the current matrix with the identity matrix [Diagonals have 1, others have 0]

									
	gluLookAt(cameraRadius*sin(cameraAngle), -cameraRadius*cos(cameraAngle), cameraHeight, 0, 0, 100, 0, 0, 1);

	//again select MODEL-VIEW
	glMatrixMode(GL_MODELVIEW);



	smallSofaSet();//smallSofaSet();

	bigSofaWithRightSide();//bigSofaWithRightSide();

	lamp_With_Stand();//lamp_With_Stand();

	glPushMatrix();{//fire_Place();
					glTranslatef(-250,0,-10);
					fire_Place();
	}glPopMatrix();

	center_Object();//	center_Object();

	glPushMatrix();{//mirror_On_The_Wall_Square();

               glTranslatef(-250, 250, 350); 
	           mirror_On_The_Wall_Square();

	}glPopMatrix();

	glPushMatrix(); {   // mirror_On_The_Wall_Round();

		glTranslatef(-250, 0, 300);
		glScalef(2, 2, 3);	
		mirror_On_The_Wall_Round();

	}glPopMatrix();

	roundChair();//roundChair();
	
	wallOfBoundary();//wallOfBoundary();
	//sofaStand();

	glutSwapBuffers();
}

void animate() {
	

	if (roted==1) {

		cameraAngle += speed;
	}

	else if (forward==1) {

		if (cameraRadius > 10)
		{
			cameraRadius -= speed * 100;
		}
		else
		{
			cameraRadius = 600;
		}
	}

	glutPostRedisplay();	//this will call the display AGAIN

}

void init() {
	//codes for initialization

	cameraAngle = 0;	//angle in radian
	move_X = 0;
	move_Y = 0;
	move_Z = 0;
	speed = 0.0001;

	cameraAngleDelta = .001;

	cameraRadius = 490;
	cameraHeight = 150;

	//clear the screen
	glClearColor(0, 0, 0, 0);


	glMatrixMode(GL_PROJECTION);

	//initialize the matrix
	glLoadIdentity();



	gluPerspective(70, 1, 0.1, 10000.0);

}

void keyboardListener(unsigned char key, int x, int y) {
	switch (key) {

	case '1':
		move_X += 1;
		if (forward==0) {
			roted = 0;
			cameraRadius = 490;
			cameraAngle = 0;
			forward = 1;
		}
		else {
			cameraRadius = 490;
			cameraAngle = 0;
			forward = 0;

		}
		break;

	case '2':
		//move_X -= 1;

		if (roted==0) {
			forward = 0;
			cameraRadius = 200;
			cameraAngle = 0;
			roted = 1;

		}
		else {
			cameraRadius = 600;
			cameraAngle = 0;
			roted = 0;

		}
		break;

	case '3':
		 movePress= ++ movePress % 2;
		break;

	case 'p':
		break;

	default:
		break;
	}
}

void specialKeyListener(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_DOWN:		//down arrow key
		cameraRadius += 10;
		break;
	case GLUT_KEY_UP:		// up arrow key
		if (cameraRadius > 10)
			cameraRadius -= 10;
		break;

	case GLUT_KEY_RIGHT:
		cameraAngle += 0.1;
		break;
	case GLUT_KEY_LEFT:
		cameraAngle -= 0.1;
		break;

	case GLUT_KEY_PAGE_UP:
		cameraHeight += 10;
		break;
	case GLUT_KEY_PAGE_DOWN:
		cameraHeight -= 10;
		break;

	default:
		break;
	}
}



int main(int argc, char **argv) {

	glutInit(&argc, argv);							//initialize the GLUT library

	glutInitWindowSize(1000, 800);
	glutInitWindowPosition(100, 100);


	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);

	glutCreateWindow("Classroom");

	init();						//codes for initialization

	glEnable(GL_DEPTH_TEST);	//enable Depth Testing

	glutDisplayFunc(display);	//display callback function
	glutIdleFunc(animate);		//what you want to do in the idle time (when no drawing is occuring)

	glutKeyboardFunc(keyboardListener);
	glutSpecialFunc(specialKeyListener);



	glutMainLoop();		//The main loop of OpenGL

	return 0;
}
