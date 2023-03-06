#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char  id[4];
    char  nome[20];
    char data[12];
} paciente;

void cadastro(paciente s);
int pacientesSalvos(paciente s, int y);

int main(void)
{
    paciente s;
    s.nome[0] = '\0';
    s.data[0] = '\0';
    s.id[0] = '\0';

    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Cadastro");

    int telas = 0;
    int letterCountName = 0;
    int letterCountDate = 0;
    int letterCountId = 0;
    int barra = 0;

    Rectangle CaixaNome = { 70, 180, 660, 50 };
    Rectangle CaixaData = { 70, 280, 325, 50 };
    Rectangle CaixaID = { 405, 280, 325, 50 };
    Rectangle Botao = { 319, 370, 162, 50 };
    Rectangle BotaoPaciente = { 580, 10, 210, 50 };
    Rectangle BotaoVoltar = { 740, 420,50,20};

    bool mouseDoNome = false;
    bool mouseDaData = false;
    bool mouseDoID = false;
    bool mostrarPacientes = true;

    int framesCounter = 0;

    SetTargetFPS(60);


    while (!WindowShouldClose())
    {
    switch(telas)
    {
        case 0:

        if (CheckCollisionPointRec(GetMousePosition(), CaixaNome) && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            {
            mouseDoNome = true;
            mouseDaData = false;
            mouseDoID = false;
            }
        else if (CheckCollisionPointRec(GetMousePosition(), CaixaData) && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            {
            mouseDoNome = false;
            mouseDaData = true;
            mouseDoID = false;
            }
        else if (CheckCollisionPointRec(GetMousePosition(), CaixaID) && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            {
            mouseDoNome = false;
            mouseDaData = false;
            mouseDoID = true;
            }
        else
        {
            if(IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                {
                mouseDoNome = false;
                mouseDaData = false;
                mouseDoID = false;
                }
        }

        if(CheckCollisionPointRec(GetMousePosition(), Botao) && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            cadastro(s);
            letterCountName = 0;
            letterCountDate = 0;
            letterCountId = 0;
            s.nome[0] = '\0';
            s.data[0] = '\0';
            s.id[0] = '\0';
            WaitTime(1);
        }
        if(CheckCollisionPointRec(GetMousePosition(), BotaoPaciente) && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            telas = 1;
        }

        if (mouseDoNome)
        {
            SetMouseCursor(MOUSE_CURSOR_IBEAM);


            int key = GetCharPressed();


                if ((key >= 32) && (key <= 125) && (letterCountName < 20))
                {
                    s.nome[letterCountName] = (char)key;
                    s.nome[letterCountName+1] = '\0';
                    letterCountName++;
                }

                key = GetCharPressed();

            if (IsKeyPressed(KEY_BACKSPACE))
            {
                letterCountName--;
                if (letterCountName < 0) letterCountName = 0;
                s.nome[letterCountName] = '\0';
            }
        }
        if (mouseDaData)
        {
            SetMouseCursor(MOUSE_CURSOR_IBEAM);


            int key = GetCharPressed();


                if ((key >= 32) && (key <= 125) && (letterCountDate < 12))
                {
                    s.data[letterCountDate] = (char)key;
                    s.data[letterCountDate+1] = '\0';
                    letterCountDate++;
                }

                key = GetCharPressed();

            if (IsKeyPressed(KEY_BACKSPACE))
            {
                letterCountDate--;
                if (letterCountDate < 0) letterCountDate = 0;
                s.data[letterCountDate] = '\0';
            }
        }

        if (mouseDoID)
        {
            SetMouseCursor(MOUSE_CURSOR_IBEAM);


            int key = GetCharPressed();


                if ((key >= 32) && (key <= 125) && (letterCountId < 3))
                {
                    s.id[letterCountId] = (char)key;
                    s.id[letterCountId+1] = '\0';
                    letterCountId++;
                }

                key = GetCharPressed();

            if (IsKeyPressed(KEY_BACKSPACE))
            {
                letterCountId--;
                if (letterCountId < 0) letterCountId = 0;
                s.id[letterCountId] = '\0';
            }
        }

        else SetMouseCursor(MOUSE_CURSOR_DEFAULT);

        if (mouseDoNome || mouseDaData || mouseDoID) framesCounter++;
        else framesCounter = 0;

        BeginDrawing();

            ClearBackground(WHITE);

            DrawText("Developed by Diogo Lima e Luis Otavio ", 10, 430, 20, BLACK);
            DrawText("Digite o nome: ", 70, 160, 20, BLACK);
            DrawText("Data de nascimento: ", 70, 260, 20, BLACK);
            DrawText("Digite o ID: ", 405, 260, 20, BLACK);

            DrawRectangleRec(CaixaNome, WHITE);
            DrawRectangleRec(CaixaData, WHITE);
            DrawRectangleRec(CaixaID, WHITE);
            DrawRectangleRec(Botao, WHITE);
            DrawRectangleLines((int)Botao.x, (int)Botao.y, (int)Botao.width, (int)Botao.height, BLACK);
            DrawText("Salvar", (int)Botao.x + 15, (int)Botao.y + 8, 40, BLACK);
            DrawRectangleRec(BotaoPaciente, WHITE);
            DrawRectangleLines((int)BotaoPaciente.x, (int)BotaoPaciente.y, (int)BotaoPaciente.width, (int)BotaoPaciente.height, BLACK);
            DrawText("Pacientes", (int)BotaoPaciente.x + 8, (int)BotaoPaciente.y + 8, 40, BLACK);

            if (mouseDoNome)
            {
                 DrawRectangleLines((int)CaixaNome.x, (int)CaixaNome.y, (int)CaixaNome.width, (int)CaixaNome.height, BLACK);
                 DrawRectangleLines((int)CaixaData.x, (int)CaixaData.y, (int)CaixaData.width, (int)CaixaData.height, DARKGRAY);
                 DrawRectangleLines((int)CaixaID.x, (int)CaixaID.y, (int)CaixaID.width, (int)CaixaID.height, DARKGRAY);
            }
            else if (mouseDaData)
                {
                 DrawRectangleLines((int)CaixaData.x, (int)CaixaData.y, (int)CaixaData.width, (int)CaixaData.height, BLACK);
                 DrawRectangleLines((int)CaixaNome.x, (int)CaixaNome.y, (int)CaixaNome.width, (int)CaixaNome.height, DARKGRAY);
                 DrawRectangleLines((int)CaixaID.x, (int)CaixaID.y, (int)CaixaID.width, (int)CaixaID.height, DARKGRAY);
                }
            else if (mouseDoID)
                {
                DrawRectangleLines((int)CaixaID.x, (int)CaixaID.y, (int)CaixaID.width, (int)CaixaID.height, BLACK);
                DrawRectangleLines((int)CaixaData.x, (int)CaixaData.y, (int)CaixaData.width, (int)CaixaData.height, DARKGRAY);
                DrawRectangleLines((int)CaixaNome.x, (int)CaixaNome.y, (int)CaixaNome.width, (int)CaixaNome.height, DARKGRAY);
                }
            else
                {
                DrawRectangleLines((int)CaixaNome.x, (int)CaixaNome.y, (int)CaixaNome.width, (int)CaixaNome.height, DARKGRAY);
                DrawRectangleLines((int)CaixaID.x, (int)CaixaID.y, (int)CaixaID.width, (int)CaixaID.height, DARKGRAY);
                DrawRectangleLines((int)CaixaData.x, (int)CaixaData.y, (int)CaixaData.width, (int)CaixaData.height, DARKGRAY);
                }

            DrawText(s.nome, (int)CaixaNome.x + 5, (int)CaixaNome.y + 8, 40, BLACK);
            DrawText(s.data, (int)CaixaData.x + 5, (int)CaixaData.y + 8, 40, BLACK);
            DrawText(s.id, (int)CaixaID.x + 5, (int)CaixaID.y + 8, 40, BLACK);

            DrawText(TextFormat("%d/20", letterCountName), 680, 235, 20, DARKGRAY);
            DrawText(TextFormat("%d/12", letterCountDate), 345, 335, 20, DARKGRAY);
            DrawText(TextFormat("%d/3", letterCountId), 680, 335, 20, DARKGRAY);

            if (mouseDoNome)
            {
                if (letterCountName < 51)
                {
                    if (((framesCounter/20)%2) == 0) DrawText("_", (int)CaixaNome.x + 8 + MeasureText(s.nome, 40), (int)CaixaNome.y + 12, 40, BLACK);
                }
            }
             if (mouseDaData)
            {
                if (letterCountDate < 51)
                {
                    if (((framesCounter/20)%2) == 0) DrawText("_", (int)CaixaData.x + 8 + MeasureText(s.data, 40), (int)CaixaData.y + 12, 40, BLACK);
                }
            }
             if (mouseDoID)
            {
                if (letterCountId < 51)
                {
                    if (((framesCounter/20)%2) == 0) DrawText("_", (int)CaixaID.x + 8 + MeasureText(s.id, 40), (int)CaixaID.y + 12, 40, BLACK);
                }
            }
        EndDrawing();
        break;
        case 1:
            pacientesSalvos(s, barra);
            barra += (GetMouseWheelMove()*8);
            DrawRectangleLines((int)BotaoVoltar.x, (int)BotaoVoltar.y, (int)BotaoVoltar.width, (int)BotaoVoltar.height, BLACK);
            DrawText("Voltar", (int)BotaoVoltar.x + 8, (int)BotaoVoltar.y + 5, 10, BLACK);
             if(CheckCollisionPointRec(GetMousePosition(), BotaoVoltar) && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            telas = 0;
        }
    }
    }

    CloseWindow();

    return 0;
}

bool IsAnyKeyPressed()
{
    bool keyPressed = false;
    int key = GetKeyPressed();

    if ((key >= 32) && (key <= 126)) keyPressed = true;

    return keyPressed;
}

void cadastro(paciente s)
{
    FILE   *arquivo;

    arquivo = fopen("Pacientes.dat", "rb+");
    if (arquivo == NULL)
    {
        arquivo = fopen("Pacientes.dat", "wb+");
    }
    fseek(arquivo, 0*sizeof(paciente), SEEK_END);
    fwrite(&s, sizeof(paciente), 1, arquivo);
    fclose(arquivo);

}

int pacientesSalvos(paciente s, int y)
{
    FILE   *arquivo;

    arquivo = fopen("Pacientes.dat", "rb");
    if (arquivo == NULL)
    {
        printf("\n\nO arquivo esta vazio, tente novamente!!!\n\n");
        exit(1);
    }
            BeginDrawing();
            ClearBackground(WHITE);
    while (!feof(arquivo))
    {
        fread(&s,sizeof(paciente),1,arquivo);
        if (!feof(arquivo))
        {
            DrawText(s.nome,10 ,y ,30 ,BLACK);
            DrawText(s.data,400 ,y ,30 ,BLACK);
            DrawText(s.id,700 ,y ,30 ,BLACK);
            y += 60;
        }
    }
            EndDrawing();
    fclose(arquivo);
}
