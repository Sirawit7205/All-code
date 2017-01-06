a=1;
x=0;
while x>=0
x= input('Enter number: ');
if(x<0)
    return
end
n(a,1)=a;
n(a,2)=x;
if x>=85&x<=100
    n(a,3)=4;
elseif x>=75&x<=84
    n(a,3)=3.5;
elseif x>=65&x<=74
    n(a,3)=3;
elseif x>=55&x<=64
    n(a,3)=2.5;
elseif x>=45&x<=54
    n(a,3)=2;
elseif x>=35&x<=44
    n(a,3)=1.5;
elseif x>=30&x<=34
    n(a,3)=1;
else
    n(a,3)=0;
end
a=a+1;
disp(n)
end