A = input("Introduce la matriz A: ")
b = input("Introduce el vector b: ")

d = det(A)

if size(A,1)==size(b,1) then
    for i=1:size(A,2)
        Ai = A
        Ai(:,i) = b
        X(i) = det(Ai)/d
    end
    disp(X)
else
    disp("Dimensiones no compatibles")
end



