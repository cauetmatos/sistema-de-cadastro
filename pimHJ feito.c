#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>



                        //Criando a Struct de Cadastro.

   struct cadastrot
    {
    char cliente[20];
    char nome1[60];
    char email[60];
    char idade[20];
    char cpf[60];
    char tel[20];
    char senha1[20];
    char senha2[20];
    };
struct cadastrot cadastro;

    struct Login{       //Criando a Struct de Login.

    char usuarioC[20];
    char senhaC[10];

    };struct Login loginC;


   struct LoginF{       //Struct p/ Funcionario.

    char usuarioF[20];
    char senhaF[10];

    };struct LoginF loginF;

    int  opcao,opcao2;         //Variaveis gerais.
    char letra1;
    char nome5[20];
    void listacliente();       // Listar Clientes.
    void listafuncionario();   // Listar Funcionarios.
    void Menu();               // Tela Menu.
    void CadastroC();          // Cadastro Cliente.
    void CadastroF();          // Cadastro Funcionario.
    void SobreNos();           // Sobre a Empresa.
    void Sair();               // Sair do Programa.
    void dados();              // Dados da Pessoa.
    void telaLogin();          // Tela de Login.




void telaLogin(){
	int ch;
	int i = 0;
    char login [20] = "Grupopim";					// LOGIN DO USUARIO.
    char senha [20] = "pim22";	   				    // SENHA DO USUARIO.
    char login1[20] = {0};
    char senha1[20] = {0};

    system("color 8f");                             // MUDAR A COR DO SISTEMA.
	system ("cls"); 						        // LIMPAR TELA.
	printf("------------------------------------------------------------------------------\n\n");
    printf ("                        LOGIN DE CADASTRO/CONSULTA \n\n");
    printf("\t\t\t >Loja HS CORPORATION\n\n");
    printf("------------------------------------------------------------------------------\n\n\n");		            // CABECALHO.
    printf ("\t\t\tDIGITE O USUARIO:");			        // MENSAGEM FIXA.
    scanf ("%s",login1);                                // LEITURA DO LOGIN.
    printf("\n");
    printf ("\t\t\tDIGITE A SENHA..:");			        // MENSAGEM FIXA.


    while (ch !=13)                                     // VERIFICAÇÃO DE LOGIN.
	{
		ch = getch();
		if (ch == 13)
			break ;
            fflush (stdin);
		if (ch == 8)
		{
			if(i==0)
			continue;
			--i;
           // system("cls");

			for(int a=0;a<i;a++)
				printf("*");                           // MASCARA PARA SENHA.
			continue;
		}
		printf("*");
		senha1[i] = ch;
		i++;
	}

    if((strcmp(login, login1)== 0 && strcmp(senha, senha1)== 0))   // VALIDACAO DO LOGIN E SENHA.
    {
        printf(" \n\n\n\n\n\t\t\tLOGADO COM SUCESSO !!!\n\n");   // MENSAGEM NA TELA.
        getchar();							                    // LOOPING DE 1 SEGUNDO.
        Menu();                                                // DIRECIONAR AO MENU PRINCIPAL.
    }
        else
        printf("\n\n\n\n\t\t\tLOGIN OU SENHA INVALIDA!!!\n\n");
        getchar();                                               // CASO O LOGIN OU A SENHA FOREM DIGITADAS ERRADAS.
        telaLogin();

}




void Menu(){                                                    // VOID DO MENU INICIAL.
            system("color 0f");
            system("cls");
            printf("------------------------------------------------------------");
            printf("\n");
            printf("\t Loja HARDWARE E SOFTWARE CORPORATION\n");
            printf("------------------------------------------------------------\n\n");
            printf("\t1- Cadastrar Cliente\n");
            printf("\t2- Listar Cliente\n");
            printf("\t3- Cadastro de funcionario\n");
            printf("\t4- Listar funcionario\n");
            printf("\t5- Sobre Nos\n");
            printf("\t6- Sair\n");
            printf("_____________________________________________________________\n\n");
            printf("\n\tEscolha uma alternativa:  ");
           // getchar();

            do{
                scanf("%d",&opcao);                             // LER UMA DAS OPCOES DO MENU.

                switch(opcao){
                    case 1 :
                    CadastroC();                               // IRA SER REDIRECIONADO AO CADASTRO DE CLIENTE.
                    fflush (stdin);
                    break;

                    case 2 :
                    listacliente();                           //  IRA SER REDIRECIONADO A LISTA DE TODOS OS CLIENTES QUE FIZERAM CADASTRO.
                    fflush (stdin);
                    break;

                    case 3 :
                    CadastroF();                               // IRA SER REDIRECIONADO AO CADASTRO DE FUNCIONARIO.
                    fflush (stdin);
                    break;

                    case 4 :
                    listafuncionario();                       //  IRA SER REDIRECIONADO A LISTA DE TODOS OS FUNCIONARIOS QUE FIZERAM CADASTRO.
                    fflush (stdin);
                    break;

                    case 5 :
                    SobreNos();                               //  IRA SER REDIRECIONADO A UMA TELA EXPLICANDO SOBRE A NOSSA EMPRESA E NOSSA POLITICA.
                    fflush (stdin);
                    break;

                    case 6 :
                    Sair();
                    fflush (stdin);                            // IRA SER REDIRECIONADO A UMA TELA ESPECIFICA PARA FECHAR O PROGRAMA.
                    exit(1);
                    break;

                    default:
                    printf("\nOpção Inválida!\n");            // CASO NENHUMA DAS OPCAOS SEJAM SELECIONADAS, AGUARDA UMA OPÇÃO VALIDA.
                    printf("\n");
                    Menu();
                    getchar();
                    }
            }while(opcao!=6);
             getchar();

}

void main(){
    setlocale(LC_ALL, "Portuguese");                           //TELA DE LOGIN.
    telaLogin();


    }

void dados(){
    FILE *ind_arq;
    ind_arq = fopen("grupopim.txt", "w");                       //ABERTURA DO ARQUIVO.



    if (ind_arq == NULL){
        printf("\nErro na abertura do arquivo!");              // MSG DE ERROR AO ABRIR O ARQUIVO.
    }
    else{
        printf("========CADASTRO========\n");
        printf("\nDigite seu Nome:");
        fgets(cadastro.nome1,60,stdin);
        printf("\nDigite sua Idade: ");
         fgets(cadastro.idade,20,stdin);

        printf("\nDigite seu Email: ");
        fgets(cadastro.email,60,stdin);

        printf("\nTelefone para Contato: ");                  // LER O CONTEUDO DE CADASTRO QUE ESTÁ SALVO NO ARQUIVO.
               fgets(cadastro.tel,20,stdin);

        printf("\nDigite seu CPF: ");
                fgets(cadastro.cpf,60,stdin);

        printf("\nDigite uma Senha: ");
             fgets(cadastro.senha1,20,stdin);

        printf("\nDigite Novamente a Senha: ");
              fgets(cadastro.senha2,20,stdin);

        cadastro.nome1[strcspn(cadastro.nome1,"\n")] = '\0';
        fwrite(&cadastro,sizeof(struct cadastrot),1,ind_arq);   // TESTE DE SALVAR A GRAVAÇÃO DO ARQUIVO.
        if (ferror(ind_arq)){
            printf("\nErro na gravação\n");                     // ERROR NA GRAVAÇAO DO ARQUIVO.

        }else{
                printf("Gravação OK\n");                        // GRAVAÇÃO SALVA.
                }

                if(!fclose(ind_arq)){
                    printf("\nFechar: Sucesso no fechamento\n");

                }else{                                          // FECHAR O ARQUIVO.

                        printf("\nFechar: Erro no fechamento\n");
                        }


    }

}

void listacliente(){                                                  // LISTAR DADOS DOS CLIENTES CADASTRADOS.
    char cliente[20];

    FILE *cadastro_cliente;
    cadastro_cliente = fopen("grupopimc.txt", "ab+");                // ABERTURA DO ARQUIVO.

    while(fgets(cliente,20, cadastro_cliente) != NULL)               // LEITURA DO ARQUIVO.
        printf("%s",cliente);


    fclose(cadastro_cliente);                                       // FECHANDO O ARQUIVO.
    system("pause");
    Menu();                                                         // SERA REDIRECIONADO A TELA DE MENU.



}

void listafuncionario(){                                            // LISTAR DADOS DOS FUNCIONARIOS CADASTRADOS.
    char funcionario[20];

    FILE *cadastro_funcionario;
    cadastro_funcionario = fopen("grupopimf.txt", "ab+");           // ABERTURA DO ARQUIVO.

    while(fgets(funcionario, 20, cadastro_funcionario) != NULL)    // LEITURA DO ARQUIVO.
        printf("%s", funcionario);


    fclose(cadastro_funcionario);                                  // FECHANDO O ARQUIVO.

    system("pause");
    Menu();                                                        // SERA REDIRECIONADO A TELA DE MENU.


}

void CadastroC(){

        system("cls");
        printf("========CADASTRO CLIENTE========\n");
        printf("\nDigite seu Nome:");
        scanf("%s", &cadastro.nome1);
        fflush (stdin);

        printf("\nDigite sua Idade: ");
        scanf("%s", &cadastro.idade);
        fflush (stdin);

        printf("\nDigite seu Email: ");
        scanf("%s", &cadastro.email);
        fflush (stdin);
                                                                // TELA DE CADASTRO DE CLIENTES.
        printf("\nTelefone para Contato: ");
        scanf("%s", &cadastro.tel);
        fflush (stdin);

        printf("\nDigite seu CPF: ");
        scanf("%s", &cadastro.cpf);
        fflush (stdin);

        printf("\nDigite uma Senha: ");
        scanf("%s", &cadastro.senha1);
        fflush (stdin);

        printf("\nDigite Novamente a Senha: ");
        scanf("%s", &cadastro.senha2);
        fflush (stdin);


        FILE *cadastro_cliente;
        cadastro_cliente = fopen("grupopimc.txt", "ab+");       // ABERTURA DO ARQUIVO.

        if (cadastro_cliente == NULL)
            {
            printf("\nErro na abertura do arquivo!");           // ERROR AO ABRIR O ARQUIVO.
            }
    else{
        fprintf(cadastro_cliente,"========CADASTRO========\n");
        fprintf(cadastro_cliente,"Digite seu Nome:%s\n", &cadastro.nome1);
        fprintf(cadastro_cliente,"Digite sua Idade:%s\n", &cadastro.idade);
        fprintf(cadastro_cliente,"Digite seu Email:%s\n", &cadastro.email);
        fprintf(cadastro_cliente,"Telefone para Contato:%s\n", &cadastro.tel);          // CADASTRO DE CLIENTE.
        fprintf(cadastro_cliente,"Digite seu CPF: %s\n", &cadastro.cpf);
        fprintf(cadastro_cliente,"Digite uma Senha: %s\n\n", &cadastro.senha1);
        fprintf(cadastro_cliente,"Digite uma Senha: %s\n\n", &cadastro.senha2);

        fclose(cadastro_cliente);                                                       // FECHANDO O ARQUIVO.

    }  if(strcmp(cadastro.senha1, cadastro.senha2)== 0 )                                // VALIDACAO DA SENHA.


            {
                system("cls");                                                          // LIMPA A TELA.
                printf("\nUsuario Cadastrado!\n\n");


                printf("Desejar Voltar para o Menu? \nAperte 's' ou qualquer tecla para sair!\n");
                scanf("%s", &letra1);

                        if (letra1 == 's')
                            {
                                Menu();                                                 // SERA REDIRECIONADO A TELA DE MENU.

                            }
                                    else{Sair();                                        // SERA REDIRECIONADO A TELA DE SAIR DO PROGRAMA.
                                            exit(1);
                                        }
            }
                else{
                system("cls");
                printf("\nSenha Invalida!! Tente Novamente mais tarde..\n\n");          // CASO A SENHA SEJA INVALIDA, VOLTA PARA O MENU.
                printf("\n");
                system("pause");
                Menu();

                 }

    }

void CadastroF(){

        system("cls");
        printf("========CADASTRO FUNCIONARIO========\n");
        printf("\nNome do Funcionario: ");
        scanf("%s", &cadastro.nome1);
        fflush (stdin);

        printf("\nCPF: ");
        scanf("%s", &cadastro.cpf);                                                           // TELA DE CADASTRO DE FUNCIONARIO.
        fflush (stdin);

        printf("\nTel/Cel: ");
        scanf("%s", &cadastro.tel);
        fflush (stdin);

        printf("\nFuncionario Cadastrado com Sucesso!!\n\n");
        printf("\n");
        system("pause");
        system("cls");
        printf("\nDesejar Voltar para o Menu? \nAperte 's' ou qualquer tecla para sair!\n");
        scanf("%s", &letra1);                                                                   // VERIFICAÇÃO DE OPÇÃO

        FILE *cadastro_funcionario;
        cadastro_funcionario = fopen("grupopimf.txt", "ab+");                           // ABERTURA DO ARQUIVO.

        if (cadastro_funcionario == NULL)
        {
        printf("\nErro na abertura do arquivo!");                                       // CASO NAO TENHA FUNCIONARIO CADASTRADO MENSAGEM DE ERROR.
        }
    else{

        fprintf(cadastro_funcionario,"========CADASTRO========\n");

        fprintf(cadastro_funcionario,"Nome do Funcionario: %s\n",&cadastro.nome1);     // CASO NAO TENHA FUNCIONARIO CADASTRADO, PEDE PARA FAZER UM CADASTRO .
        fprintf(cadastro_funcionario,"CPF: %s\n",&cadastro.cpf);
        fprintf(cadastro_funcionario,"Tel/Cel: %s\n\n",&cadastro.tel);

        fclose(cadastro_funcionario);                                                  // FECHA O ARQUIVO.

        }


            if (letra1 == 's')
                {
                Menu();                                                                // SERA REDIRECIONADO A TELA DE MENU .

                }
                    else{Sair();                                                       // SERA REDIRECIONADO A TELA DE SAIR DO PROGRAMA
                        exit(1);
                        }
        }

void SobreNos(){                                                                       // TELA QUE CONTA SOBRE A NOSSA EMPRESA .

        system("cls");
        printf("\n\n\t\t\t\t\tLOJA HARDWARE E SOFTWARE CORPORATION\n");
        printf("\t\t\t      -------------------------------------------------------\n\n");
        printf("\nNossa principal missao e fornecer aos nossos clientes as melhores e maiores ofertas do mercado, de produtos que possuem qualidade e seguranca, atraves do    contato que temos com muitos fabricantes fora do pais, oferecemos essa oportunidade a voce, futuro cliente, de poder adquirir produtos de ponta com o melhor preco do mercado, Voces clientes sao o nosso   foco principal, e por isso, somos sempre transparentes, diretos e verdadeiros. Acreditamos que o comprometimento e o   que constroi nossa reputacao a cada dia e nos da tanta credibilidade. Sentimo-nos honrados em poder servi-lo, lhe       proporcionar a melhor experiencia na hora da compra e garantia de satisfacao. Agir de forma honesta e ser transparente e o nosso principal diferencial. A Loja HS CORPORATION é composta por uma equipe disposta e atenciosa, trabalhamos \ndiariamente para oferecer a voce uma grande variedade de produtos que acompanham as ultimas tendencias do mundo. \nPossuimos um excelente servico de atendimento, o que permite a aproximacao total do cliente ao produto desejado. \nQualquer duvida entre em contato conosco: email: contato@lojasoft.com.br Teremos muito prazer em lhe atender e ajudar!. \nUm abraco, equipe SoftProblem.\n\n\n");
        fflush (stdin);
        system("pause");


            system("cls");                                                             //LIMPA TELA.
            printf("\nDesejar Voltar para o Menu? \nAperte 's' ou qualquer tecla para sair!\n");
            scanf("%s", &letra1);                                                      // VERIFICAÇÃO DE OPÇÃO.

            if (letra1 == 's')
                {
                Menu();                                                                // VOLTA PARA A TELA DE MENU .

                }
                    else{Sair();                                                       // SERA REDIRECIONADO A TELA DE SAIR DO PROGRAMA.
                exit(1);
                        }
        }

void Sair(){                                                                           // TELA DE FECHAMENTO DO PROGRAMA.

        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tObrigado por Acessar! Volte Sempre..");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        system("pause");
       getchar();
        }





