//
//  main.cpp
//  CGProject
//
//  Created by Miguel Veloso on 19/05/15.
//  Copyright (c) 2015 Miguel Veloso. All rights reserved.
//

#include <iostream>
#include <OpenGL/glu.h>
#include <OpenGL/gl.h>

#ifdef _WIN32
#include <GL/glut.h>
#elif __APPLE__
#include <GLUT/glut.h>
#elif __linux__
#include <GL/glut.h>
#endif

int CurrentMode = 3;

void draw(void){
    
    // Clear the rendering window
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Set drawing color to white
    glColor3f( 1.0, 1.0, 1.0 );
    
    switch (CurrentMode)
    {
            
        case 0:
            // Draw three points
            glBegin(GL_POINTS);
            glVertex2f( 1.0, 1.0 );
            glVertex2f( 2.0, 1.0 );
            glVertex2f( 2.0, 2.0 );
            glEnd();
            break;
            
        case 1:
        case 2:
        case 3:
            if ( CurrentMode==1 ) {
                // Draw lines in GL_LINES mode
                glBegin( GL_LINES );
            }
            else if ( CurrentMode==2 ) {
                // Draw lines in GL_LINE_STRIP mode
                glBegin( GL_LINE_STRIP );
            }
            else {
                // Draw lines in GL_LINE_LOOP mode
                glBegin( GL_LINE_LOOP );
            }
            glVertex2f( 0.5, 1.0 );
            glVertex2f( 2.0, 2.0 );
            glVertex2f( 1.8, 2.6 );
            glVertex2f( 0.7, 2.2 );
            glVertex2f( 1.6, 1.2 );
            glVertex2f( 1.0, 0.5 );
            glEnd();
            break;
            
        case 4:			// Overlapping triangles
            glBegin( GL_TRIANGLES );
            glColor3f( 1.0, 0.0, 0.0 );
            glVertex3f( 0.3, 1.0, 0.5 );
            glVertex3f( 2.7, 0.85, 0.0 );
            glVertex3f( 2.7, 1.15, 0.0 );
            
            glColor3f( 0.0, 1.0, 0.0 );
            glVertex3f(2.53, 0.71, 0.5 );
            glVertex3f(1.46, 2.86, 0.0 );
            glVertex3f(1.2, 2.71, 0.0 );
            
            glColor3f( 0.0, 0.0, 1.0 );
            glVertex3f(1.667, 2.79, 0.5);
            glVertex3f(0.337, 0.786, 0.0);
            glVertex3f(0.597, 0.636, 0.0);
            glEnd();
    }
    
    // Flush the pipeline.  (Not usually necessary.)
    glFlush();
    
}

int main(int argc, char * argv[]) {
    
    glutInit(&argc,argv);
    
    // The image is not animated so single buffering is OK.
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH );
    
    // Window position (from top corner), and size (width and hieght)
    glutInitWindowPosition( 20, 60 );
    glutInitWindowSize( 1366, 728 );
    glutCreateWindow( "SimpleDraw - Press space bar to toggle images" );
    
    
    // call this whenever window needs redrawing
    glutDisplayFunc( draw );
    
    // Start the main loop.  glutMainLoop never returns.
    glutMainLoop(  );
    
    return(0);	// This line is never reached.
    
}
