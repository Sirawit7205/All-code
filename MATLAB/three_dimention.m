%-----3D graph plot-----

%t=0:0.1:10*pi;
%x=(1-t.^2).*sin(t);
%y=1+cos(t);
%z=t;
%plot3(x,y,z)
%grid on

%-----3D mesh/surface/contour plot-----
x=1:5;
y=1:4;
[X,Y]=meshgrid(x,y);
Z=Y.*X./(X+Y.^2);
%mesh(X,Y,Z)
%surf(X,Y,Z)
%contour(X,Y,Z,15)
contourf(X,Y,Z,15) %<--- Contour Surface plot
axis square