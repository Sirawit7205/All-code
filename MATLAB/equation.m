%Equation roots checker%
%Sirawit Lappisatepun M.4/6 No.29%
clear;
clc;
a=input('Input coefficient a: ');
b=input('Input coefficient b: ');
c=input('Input coefficient c: ');
%find discriminant of the equation%
D=(b^2)-(4*a*c);
fprintf('Discriminant value of this equation = %d\n',D);
if D<0
    disp('The equation have no real root.');
elseif D==0
    disp('The equation have one real root.');
    ans1=(-b+sqrt(D))/2;
    fprintf('Root is %8.2f\n',ans1);
else
    disp('The equation have two real roots.');
    ans1=(-b+sqrt(D))/2;
    ans2=(-b-sqrt(D))/2;
    fprintf('Roots are %8.2f %8.2f\n',ans1,ans2);
end


