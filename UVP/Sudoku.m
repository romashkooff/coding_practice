% Matice M - matice kterou chceme vyresit
% k - radek, l - sloupec, z - indikator (kontrola), i - iterace
M=[0,0,6,0,0,1,0,0,0;
    0,1,3,0,0,0,0,5,0;
    0,0,0,0,2,4,0,8,0;
    5,0,0,7,0,0,0,0,0;
    0,0,2,0,0,0,0,0,4;
    3,0,0,5,0,0,0,0,1;
    0,0,0,0,0,9,7,0,0;
    0,8,0,0,0,0,9,0,0;
    0,4,0,0,0,6,0,0,0];

[M, i] = reseni(M, 0); % 0 - jen vysledek, 1 - mezivysledky

function [M, i] = reseni(M, parametr)

% Matice X - pouzijeme prazdnou matici abychom vyresili matice M
x=zeros(9,9);

% Zaplni prazdnou matice jednickami, kde matice M ma nuly
for k=1:9
    for l=1:9
        if M(k,l)==0
            x(k,l)=1;
        end
    end
end

k=1;
z=0;
i=0;

% Projdeme vsechny prvky v matici M
while k<=9
    if parametr~=0
        disp(M);
        disp(['Iterace cislo: ', num2str(i), '     ^ ^ ^ ^ ^ ^ ^ ^']);
        disp(' ');
    end
    i=i+1;
    l=1;
    while l<=9
        % Najdeme vsechny prazdne prvky (v matici x tento prvek oznacen 1)
        if x(k,l)==1
            % Zkusme priradit hodnotu od M(k,l)+1 do 9
            for a = M(k,l)+1:9
                M(k,l)=a;
                z=0; % Oznacime, ze tato bunka je zaplnena
                % Overme, zda nemame duplikaty v radku a slouoci
                for m=1:9
                    if M(k,l)==M(k,m) && l~=m
                        z=1; % Pokud mame duplikat, tak musime vysetrit tuto bunku znova
                    end
                    if M(k,l) == M(m,l) && k~=m
                        z=1; % Pokud mame duplikat, tak musime vysetrit tuto bunku znova
                    end
                end
                % Overime, ze nemame duplikaty v matici 3x3 
                lx=floor((l-1)/3);
                ly=floor((k-1)/3);
                for p=1:3
                    for q=1:3
                        if M(k,l)==M(3*ly+p,3*lx+q) && (k~=3*ly+p || l~=3*lx+q)
                            z=1;
                        end
                    end
                end
                % Pokud duplikaty nemame, tak ukoncime smyčku
                if z==0
                    break;
                end
            end
        end

        % Vracime minulou hodnotu zpatky
        if z==1
            M(k,l)=0;
            if l==1
                for r=k-1:-1:1
                    for s=9:-1:1
                        if x(r,s)==1
                            k=r;
                            l=s-1;
                            break;
                        end
                    end
                    if x(r,s)==1
                        break;
                    end
                end
            else
                prap=0;
                for r=9:-1:1
                    for s=9:-1:1
                        if ((r<k)||(r==k&&s<l))&&(x(r,s)==1)
                            k=r;
                            l=s-1;
                            prap=1;
                            break;
                        end
                    end
                    if prap==1
                        break;
                    end
                end
            end
        end
        l=l+1;
    end
    k=k+1;
    if k == 10 && parametr ~= 0
            disp(M)
            disp(['Tato iterace je posledni: ', num2str(i), '     ^ ^ ^']);
            disp(' ');
    end 
end
    disp('-------------------------------------')
    disp('Vyresena matice:');
    disp(M);
    disp(['Celkovy pocet iteraci: ', num2str(i)]);
    disp('-------------------------------------')
end   