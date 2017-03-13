A = input("Enter A: ");
b = input("Enter b: ");

n=size(A,1);

for k=1:n-1
    for i=k+1:n
        fa=A(i,k)/A(k,k);
        for j=k:n
            A(i,j)=A(i,j)-fa*A(k,j);
        end
        b(i)=b(i)-fa*b(k);
        disp([A b]);
    end
end

for i = n: -1:2
    for j = i-1: -1: 1
        fa = A(j,i)/A(i,i);
        A(j,:) = A(j,:)-fa*A(i,:);
        b(j)=b(j)-fa*b(i);
        b(i)=b(i)/A(i,i);
        A(i,i)=A(i,i)/A(i,i);
        x(i)=b(i);
    end
    disp([A b]);
    disp(x);
end
