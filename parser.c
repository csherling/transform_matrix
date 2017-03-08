#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"
#include "parser.h"


/*======== void parse_file () ==========
Inputs:   char * filename 
          struct matrix * transform, 
          struct matrix * pm,
          screen s
Returns: 

Goes through the file named filename and performs all of the actions listed in that file.
The file follows the following format:
     Every command is a single character that takes up a line
     Any command that requires arguments must have those arguments in the second line.
     The commands are as follows:
         line: add a line to the edge matrix - (1)
	    takes 6 arguemnts (x0, y0, z0, x1, y1, z1)
	 ident: set the transform matrix to the identity matrix - (5)
	 scale: create a scale matrix,  (2)
	    then multiply the transform matrix by the scale matrix - 
	    takes 3 arguments (sx, sy, sz)
	 move: create a translation matrix, (3)
	    then multiply the transform matrix by the translation matrix - 
	    takes 3 arguments (tx, ty, tz)
	 rotate: create an rotation matrix, (4)
	    then multiply the transform matrix by the rotation matrix -
	    takes 2 arguments (axis, theta) axis should be x y or z
	 apply: apply the current transformation matrix to the (6)
	    edge matrix
	 display: draw the lines of the edge matrix to the screen (7)
	    display the screen
	 save: draw the lines of the edge matrix to the screen (8)
	    save the screen to a file -
	    takes 1 argument (file name)
	 quit: end parsing (9)

See the file script for an example of the file format


IMPORTANT MATH NOTE:
the trig functions int math.h use radian mesure, but us normal
humans use degrees, so the file will contain degrees for rotations,
be sure to conver those degrees to radians (M_PI is the constant
for PI)
====================*/
void parse_file ( char * filename, 
                  struct matrix * transform, 
                  struct matrix * edges,
                  screen s) {

  FILE *f;
  char * line = (char *)malloc(256);
  clear_screen(s);
  /* int com = 0; */
  color color;
  color.red = MAX_COLOR;
  color.green = MAX_COLOR;
  color.blue = MAX_COLOR;

  struct matrix * temp;
  temp = new_matrix(4, 4);  
  ident(temp);
  
  if ( strcmp(filename, "stdin") == 0 ) 
    f = stdin;
  else
    f = fopen(filename, "r");
  
  while ( fgets(line, 255, f) != NULL ) {
    /* fgets(line, 255, f); */
    line[strlen(line)-1]='\0';
    printf("\n:%s:",line);
    fflush(stdout);
    /* if(com == -1){ */
    /*   if(strcmp(line,"line") == 0) com = 1; */
    /*   else if(strcmp(line,"scale") == 0) com = 2; */
    /*   else if(strcmp(line,"move") == 0) com = 3; */
    /*   else if(strcmp(line,"rotate") == 0) com = 4; */
    /*   else if(strcmp(line,"ident") == 0) com = 5; */
    /*   else if(strcmp(line,"apply") == 0) com = 6; */
    /*   else if(strcmp(line,"display") == 0) com = 7; */
    /*   else if(strcmp(line,"save") == 0) com = 8; */
    /*   else if(strcmp(line,"quit") == 0) com = 9; */
    /* } */
    if(line[0]>=97 && line[0]<=119){
      if(strncmp(line,"line",4) == 0){
	printf("---1---");
	fgets(line, 255, f);
	add_edge(edges,atof(strsep(&line," ")),atof(strsep(&line," ")),atof(strsep(&line," ")),atof(strsep(&line," ")),atof(strsep(&line," ")),atof(line));
      }
      else if(strncmp(line,"scale",5) == 0){
	printf("---2---");
	fgets(line, 255, f);
	matrix_mult(make_scale(atof(strsep(&line," ")),atof(strsep(&line," ")),atof(line)), transform);
      }
      else if(strncmp(line,"move",4) == 0){
	printf("---3---");
	fgets(line, 255, f);
	matrix_mult(make_translate(atof(strsep(&line," ")),atof(strsep(&line," ")),atof(line)), transform);
      }
      else if(strncmp(line,"rotate",6) == 0){
	printf("---4---");
	fgets(line, 255, f);
	char * dir = strsep(&line, " ");
	if(strcmp(dir,"x") == 0) matrix_mult(make_rotX(atof(line)), transform);
	else if(strcmp(dir,"y") == 0) matrix_mult(make_rotY(atof(line)), transform);
	else if(strcmp(dir,"z") == 0) matrix_mult(make_rotZ(atof(line)), transform);
	printf("\n%s\n", line);
      }
      else if(strncmp(line,"ident",5) == 0){
	printf("---5---");
	ident(transform);
      }
      else if(strncmp(line,"apply",5) == 0){
	printf("---6---");
	matrix_mult(transform, edges);
      }
      else if(strncmp(line,"display",7) == 0){
	printf("---7---");
	clear_screen(s);
	draw_lines(edges, s, color);
	display(s);
      }
      else if(strncmp(line,"save",4) == 0){
	printf("---8---");
	clear_screen(s);
	draw_lines(edges, s, color);
	save_extension(s, "transform.png");
      }
      else if(strncmp(line,"quit",4) == 0){
	printf("---9---");
	free(line);
	break;
      }
      /* printf("%d alpha", com); */
	print_matrix(edges);
    }
  }
}
  
