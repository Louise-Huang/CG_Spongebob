#include <stdio.h>
#include <GL/glut.h>
#include "glm.h"
#include <windows.h>
#include <mmsystem.h>
#include "CMP3_MCI.h"
//#include <opencv/highgui.h>
CMP3_MCI myMP3;
GLMmodel*pmodel=NULL;
GLMmodel*pmodel2=NULL;
GLMmodel*pmodel3=NULL;
GLMmodel*pmodel4=NULL;
GLMmodel*pmodel5=NULL;
GLMmodel*pmodel6=NULL;
GLMmodel*pmodel7=NULL;
GLMmodel*pmodel8=NULL;
float rot[10]={0}, rotOld[10]={0}, rotNew[10]={0};
int rotNow=0, oldX=0, oldY=0;
FILE *fout=0, *fin=0;
void timer(int t)
{
    float alpha=(t%10)/10.0;///!!!!
    //pos = newX*alpha+oldX*(1-alpha);
    if(t%10==0){
        if(fin==NULL) fin=fopen("motion.txt", "r");
        for(int i=0;i<5;i++){
            rotOld[i]=rotNew[i];
            fscanf(fin, "%f", &rotNew[i]);
        }
    }
    for(int i=0;i<5;i++){
        rot[i]=rotNew[i]*alpha+rotOld[i]*(1-alpha);
    }
    glutTimerFunc(100, timer, t+1);
    glutPostRedisplay();
}
void display()
{
    /*IplImage * img=cvLoadImage("image.jpg");
    cvNamedWindow("opencv");
    cvShowImage("opencv",img);
    cvWaitKey(0);
    */

    glClearColor(0,1,0,0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    {
        glPushMatrix();

            glRotatef(rot[4],0,1,0);


            if(!pmodel){///body
            pmodel=glmReadOBJ("sponge.obj");
            if(!pmodel) exit(0);
            glmUnitize(pmodel);
            glmFacetNormals(pmodel);
            glmVertexNormals(pmodel, 90.0);
            }
            glPushMatrix();
                glRotatef(180, 0,1,0);//y軸旋轉150度
                glScalef(0.5,0.4,0.5);
                glmDraw(pmodel, GLM_SMOOTH | GLM_MATERIAL);
            glPopMatrix();

            {
            glPushMatrix();
                glTranslatef(-0.28,0.12,0.1);
                glRotatef(rot[0],0,0,1);
                glTranslatef(0.3,-0.12,-0.1);

                if(!pmodel2){///hand_left
                pmodel2=glmReadOBJ("hand.obj");
                if(!pmodel2) exit(0);
                glmUnitize(pmodel2);
                glmFacetNormals(pmodel2);
                glmVertexNormals(pmodel2, 90.0);
                }
                glPushMatrix();
                    glTranslatef(-0.5,0.12,0.1);
                    glRotatef(180, 0,1,0);//y軸旋轉150度
                    glScalef(0.3,0.3,0.3);
                    glmDraw(pmodel2, GLM_SMOOTH | GLM_MATERIAL);
                glPopMatrix();
            glPopMatrix();
            }
            {
            glPushMatrix();
                glTranslatef(0.28,0.12,0.1);
                glRotatef(-rot[1],0,0,1);
                glTranslatef(-0.3,-0.12,-0.1);

                if(!pmodel3){///hand_right
                pmodel3=glmReadOBJ("hand.obj");
                if(!pmodel3) exit(0);
                glmUnitize(pmodel3);
                glmFacetNormals(pmodel3);
                glmVertexNormals(pmodel3, 90.0);
                }
                glPushMatrix();
                    glTranslatef(0.5,0.12,0.1);
                    glRotatef(0, 0,1,0);//y軸旋轉150度
                    glScalef(0.3,0.3,0.3);
                    glmDraw(pmodel3, GLM_SMOOTH | GLM_MATERIAL);
                glPopMatrix();
            glPopMatrix();
            }
            {
            glPushMatrix();
                glTranslatef(-0.18,-0.4,0.08);
                glRotatef(rot[2],0,0,1);
                glTranslatef(0.18,0.4,-0.08);

                if(!pmodel4){///leg_left
                pmodel4=glmReadOBJ("foot.obj");
                if(!pmodel4) exit(0);
                glmUnitize(pmodel4);
                glmFacetNormals(pmodel4);
                glmVertexNormals(pmodel4, 90.0);
                }
                glPushMatrix();
                    glTranslatef(-0.18,-0.6,0.08);
                    glRotatef(180, 0,1,0);//y軸旋轉150度
                    glScalef(0.8,0.6,0.8);
                    glmDraw(pmodel4, GLM_SMOOTH | GLM_MATERIAL);
                glPopMatrix();
            glPopMatrix();
            }
            {
            glPushMatrix();
                glTranslatef(0.18,-0.4,0.08);
                glRotatef(-rot[3],0,0,1);
                glTranslatef(-0.18,0.4,-0.08);

                if(!pmodel5){///leg_right
                pmodel5=glmReadOBJ("foot.obj");
                if(!pmodel5) exit(0);
                glmUnitize(pmodel5);
                glmFacetNormals(pmodel5);
                glmVertexNormals(pmodel5, 90.0);
                }
                glPushMatrix();
                    glTranslatef(0.18,-0.6,0.08);
                    glRotatef(180, 0,1,0);//y軸旋轉150度
                    glScalef(0.8,0.6,0.8);
                    glmDraw(pmodel5, GLM_SMOOTH | GLM_MATERIAL);
                glPopMatrix();
            glPopMatrix();
            }
            {
            glPushMatrix();


                if(!pmodel6){///eye_left
                pmodel6=glmReadOBJ("eye.obj");
                if(!pmodel6) exit(0);
                glmUnitize(pmodel6);
                glmFacetNormals(pmodel6);
                glmVertexNormals(pmodel6, 90.0);
                }
                glPushMatrix();
                    glTranslatef(-0.11,0.2,-0.02);
                    glRotatef(180,0,1,0);//y軸旋轉150度
                    glScalef(0.16,0.14,0.1);
                    glmDraw(pmodel6, GLM_SMOOTH | GLM_MATERIAL);
                glPopMatrix();

            glPopMatrix();
            }
            {
            glPushMatrix();



                if(!pmodel7){///eye_right
                pmodel7=glmReadOBJ("eye.obj");
                if(!pmodel7) exit(0);
                glmUnitize(pmodel7);
                glmFacetNormals(pmodel7);
                glmVertexNormals(pmodel7, 90.0);
                }
                glPushMatrix();

                    glTranslatef(0.1,0.2,-0.02);
                    glRotatef(180,0,1,0);//y軸旋轉150度
                    glScalef(0.16,0.14,0.1);
                    glmDraw(pmodel7, GLM_SMOOTH | GLM_MATERIAL);
                glPopMatrix();
            glPopMatrix();

            glPopMatrix();
            }


        glPopMatrix();


    }
    glPopMatrix();

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
    if(key=='0') rotNow=0;///left_hand
    if(key=='1') rotNow=1;///right_hand
    if(key=='2') rotNow=2;///left_leg
    if(key=='3') rotNow=3;///right_leg
    if(key=='4') rotNow=4;///body

    if(key=='r'){///按小寫的r 會去讀1行/一組x,y
        if(fin==NULL) fin=fopen("motion.txt", "r");
        for(int i=0;i<5;i++){
            fscanf(fin, "%f", &rot[i]);
        }
    }
    if(key=='t'){
        if(fin==NULL) fin=fopen("motion.txt", "r");
        for(int i=0;i<5;i++){
            fscanf(fin, "%f", &rotNew[i]);
        }
        glutTimerFunc(100,timer, 0);
        glutPostRedisplay();
    }
    if(key=='s'){///!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        if(fout==NULL) fout=fopen("motion.txt", "w+");
        for(int i=0;i<5;i++){
            fprintf(fout, "%3.1f ", rot[i]);
            printf("%3.1f ", rot[i]);
        }
        fprintf(fout, "\n");
        printf("\n");
    }
    glutPostRedisplay();///電腦貼個Post-It便利貼,告訴GLUT有空要重畫畫面哦
}
void motion(int x, int y)
{
    rot[rotNow] += x-oldX;
    oldX = x;
    glutPostRedisplay();
}
void mouse(int button, int state, int x, int y)
{///先開冰箱門(滑鼠按下去),把大象塞進去(滑鼠drag),最後再關上冰箱門(起來)
    if(state==GLUT_DOWN){
        oldX=x; oldY=y;
    }
}
GLfloat pos[]={0.0,0.0,-1.0,0.0};
int main(int argc,char **argv)
{


    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Spongebob!");
    glutInitWindowSize(800,800);
    glutInitWindowPosition(200,0);
    glutDisplayFunc(display);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glLightfv(GL_LIGHT0, GL_POSITION,pos);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);  //深度測試
    myMP3.Load("music.mp3");
    myMP3.Play();



    glutMainLoop();
}

