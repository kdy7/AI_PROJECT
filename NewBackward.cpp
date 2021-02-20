#include <string.h>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <vector>
#include <stack>
#include <iostream>
#include "NewBackward.h"

using namespace std;
//Enclosed a program, which comprises the inference engine based on backward chaining.  You need it for your
//project #1.  The program contains some errors and it is not designed to be efficient.
//Modify the program to make it better and efficient.  Explain in your report how you have modified the
//program to make it better.
//MODIFICATIONS: Moved goto statements into functions -
//-could possibly use dynamic allocation for the character arrays instead
//-pass by reference would require a lot of refactoring by is more efficient as well



/*****backward chaining *******/
/* Install your IF clauses in sequence in the first case
   statement of the main program
   example: if((a1==2) && (a2==6)) s=1;
                      if(strcmp(j,NO") != 0) s=1;
   the then part of the above construction always
   contains s=1;
   install your the clauses in sequence in the second
   case statement of the main program
   example strcpy(po,"YES");
*/

/*  conclusion list */
// OLD char conclt[10][3];
vector<string> conclt(2);
/*  variable list */
// OLD char varlt[10][3];
vector<string> varlt(2);
/*  clause vairable list */
vector<string> clvarlt(240);
string varble;
//char /* qualify */ qu[4], /* degree*/ de[4];
//char /* discovery */ di[4], /* position */ po[4];
string qu,de,di,po;
string cancer, skin_issuse, change_skin, dry_skin,
       lump_breast, mole_change, persistant_cough,
       resp_infect, cough_blood, diff_swallow,
       weight_loss, swol_lymph, bone_pain,
       rectal_bleed, mouth_ulcer, abdominal_pain,
       nausea, headache, yellow_skin, trouble_urine,
       blood_urine, lower_back_pain;

char buff[128];

/* instantiated list */
//int instlt[11];
vector<int> instlt(1);
/* statement stack */
//int statsk[11];
vector<int> statsk(1);
/* clause stack */ //clausk[11],
vector<int> clausk(1);

int sn, f, i, j, s, k, /*stack pointer */ sp;

float /* grade */ gr, /*experience */ ex;

bool recursion;

void determine_member_concl_list(void);
void push_on_stack(void);
void instantiate(void);
void b520(void);
void b545(void);
void ifSwitch();
void thenSwitch(void);

NewBackward::NewBackward() {

}

void NewBackward::run_backward()
{
        /***** initialization section ******/
        /* stack space is 10 we initially place stack space at 10+1 */
        sp=27;
        for (i=1; i<27; i++)
        {
                // OLDstrcpy(conclt[i],"");
                // OLD strcpy(varlt[i],"");
                instlt.push_back(0);
                statsk.push_back(0);
                clausk.push_back(0);
        }
        //for (i=1; i<41; i++)  //OLDstrcpy(clvarlt[i],"");
        /* enter conclusions which are the variables in the then part,
        1 at a time.  enter the conclusions in exact order starting at the 1st
        if-then.  after last conclusion hit return key for rest of
        conclusions */
        init();

        /*** comment 305 *****/
        /*
        strcpy(conclt[1], "PO");
        strcpy(conclt[2], "QU");
        strcpy(conclt[3], "PO");
        strcpy(conclt[4], "PO");
        strcpy(conclt[5], "PO");
        strcpy(conclt[6], "PO");
        old code

        conclt[1] = "PO";
        conclt.push_back("QU");
        conclt.push_back("PO");
        conclt.push_back("PO");
        conclt.push_back("PO");
        conclt.push_back("PO");
        conclt.push_back("");
        */

        cout << ("*** CONCLUSION LIST ***\n");
        for (i=1; i<conclt.size(); i++)
        {
            cout << "CONCLUSION";
            cout << conclt[i] << endl;
        }


        cout << ("HIT RETURN TO CONTINUE");
        gets(buff);
        /* enter variables which are in the if part, 1 at a time in the
        exact order that they occur, up to 3 variables per if statement.  do not
        duplicate any variable names.  any name is used only once.  if no
        more variables left just hit return key. */
        printf("*** VARIABLE LIST *\n");
        /**** comment 367 *****/
        /*OLD
        strcpy(varlt[1], "DE");
        strcpy(varlt[2], "DI");
        strcpy(varlt[3], "EX");
        strcpy(varlt[4], "GR");

        varlt[1] = "DE";
        varlt.push_back("DI");
        varlt.push_back("EX");
        varlt.push_back("GR");
        */

        for(i=1; i<varlt.size(); i++) { // OLD printf("VARIABLE %d %s\n", i, varlt[i]);
         cout << "VARIABLE " << i << "\t" << varlt[i] << "\n";
        }
        printf("HIT RETURN KEY TO CONTINUE");
        gets(buff);
        /* enter variables as they appear in the if clauses.  a maximum
        of 3 variables per if statement.  if no more variables hit return key. */
        printf("*** CLAUSE VARIABLE LIST ***\n");
        /***** comment 407 through 409 ***/
        /* OLD
        strcpy(clvarlt[1], "DE");
        strcpy(clvarlt[5], "DE");
        strcpy(clvarlt[9], "DE");
        strcpy(clvarlt[10], "DI");
        strcpy(clvarlt[13], "QU");
        strcpy(clvarlt[14], "GR");
        strcpy(clvarlt[15], "EX");
        strcpy(clvarlt[17], "QU");
        strcpy(clvarlt[18], "GR");
        strcpy(clvarlt[19], "EX");
        strcpy(clvarlt[21], "QU");
        strcpy(clvarlt[22], "GR");

        clvarlt[1] = "DE";
        clvarlt[3] = " ";
        clvarlt[5] = "DE";
        clvarlt[9] = "DE";
        clvarlt[10]= "DI";
        clvarlt[13]= "QU";
        clvarlt[14]= "GR";
        clvarlt[15]= "EX";
        clvarlt[17]= "QU";
        clvarlt[18]= "GR";
        clvarlt[19]= "EX";
        clvarlt[21]= "QU";
        clvarlt[22]= "GR";
        */
        /*//OLD
        for(i=1; i<clvarlt.size(); i++)
        {
                printf("** CLAUSE %d\n", i);
                for(j=1; j<5; j++)
                { k = 4 * (i-1) + j;
                  printf("VARIABLE %d  %s\n", j, clvarlt[k]); }
                if (i==4)
                { printf("HIT RETURN KEY TO CONTINUE"); gets(buff); }
        }
        */
        ///*
        cout << "** CLAUSE VARIABLES ** \n";
        for (i = 1; i < clvarlt.size(); i++) {
            cout << "VARIABLE " << i << "\t " <<  clvarlt[i] << "\n";
        }
        //*/

        /****** inference section *****/
        printf("** ENTER CONCLUSION ? "); // OLD gets(varble);
        cin >> varble;
        /* get conclusion statement number (sn) from the conclusion list
           (conclt) */
        /* first statement starts search */
        // OLD GOTO 1 ---------
        f=1;
        determine_member_concl_list();
        recursion = false;
        recursive_search();


}

void NewBackward::init() {
    //----------- CONCLUSION LIST ----------------------

        conclt[1] = "cancer";
        for (int i = 0; i < 26; i++) {
            conclt.push_back("cancer");
        }

    //------------------------------------------------


    //----------- VARIABLE LIST ----------------------
        varlt[1] = "skin_issuse";
        varlt.push_back("change_skin");
        varlt.push_back("dry_skin");
        varlt.push_back("lump_breast");
        varlt.push_back("mole_change");
        varlt.push_back("persistant_cough");
        varlt.push_back("resp_infect");
        varlt.push_back("cough_blood");
        varlt.push_back("diff_swallow");
        varlt.push_back("weight_loss");
        varlt.push_back("swol_lymph");
        varlt.push_back("bone_pain");
        varlt.push_back("rectal_bleed");
        varlt.push_back("mouth_ulcer");
        varlt.push_back("abdominal_pain");
        varlt.push_back("nausea");
        varlt.push_back("headache");
        varlt.push_back("yellow_skin");
        varlt.push_back("trouble_urine");
        varlt.push_back("blood_urine");
        varlt.push_back("lower_back_pain");

    //------------------------------------------------


    //----------CLAUSE VARIABLE LIST -----------------
        clvarlt[1] = "skin_issuse";
        clvarlt[2] = "change_skin";
        clvarlt[3] = "dry_skin";
        clvarlt[4] = "lump_breast";

        clvarlt[9]= "skin_issuse";
        clvarlt[10]= "change_skin";
        clvarlt[11]= "dry_skin";

        clvarlt[17]= "skin_issuse";
        clvarlt[18]= "change_skin";
        clvarlt[19]= "dry_skin";
        clvarlt[20]= "lump_breast";
        clvarlt[21]= "mole_change";

        clvarlt[25]= "skin_issuse";
        clvarlt[26]= "persistant_cough";
        clvarlt[27]= "resp_infect";

        clvarlt[29]= "skin_issuse";
        clvarlt[30]= "persistant_cough";
        clvarlt[31]= "resp_infect";
        clvarlt[32]= "cough_blood";

        clvarlt[37]= "skin_issuse";
        clvarlt[38]= "persistant_cough";
        clvarlt[39]= "resp_infect";
        clvarlt[40]= "cough_blood";
        clvarlt[41]= "diff_swallow";

        clvarlt[45]= "skin_issuse";
        clvarlt[46]= "persistant_cough";
        clvarlt[47]= "resp_infect";
        clvarlt[48]= "cough_blood";
        clvarlt[49]= "diff_swallow";

        clvarlt[53]= "skin_issuse";
        clvarlt[54]= "persistant_cough";
        clvarlt[55]= "weight_loss";
        clvarlt[56]= "swol_lymph";

        clvarlt[61]= "skin_issuse";
        clvarlt[62]= "persistant_cough";
        clvarlt[63]= "weight_loss";
        clvarlt[64]= "swol_lymph";
        clvarlt[65]= "bone_pain";
        clvarlt[66]= "rectal_bleed";
        clvarlt[67]= "mouth_ulcer";

        clvarlt[69]= "skin_issuse";
        clvarlt[70]= "persistant_cough";
        clvarlt[71]= "weight_loss";
        clvarlt[72]= "swol_lymph";
        clvarlt[73]= "bone_pain";
        clvarlt[74]= "rectal_bleed";
        clvarlt[75]= "mouth_ulcer";

        clvarlt[77]= "skin_issuse";
        clvarlt[78]= "persistant_cough";
        clvarlt[79]= "weight_loss";
        clvarlt[80]= "swol_lymph";
        clvarlt[81]= "bone_pain";
        clvarlt[82]= "rectal_bleed";
        clvarlt[83]= "abdominal_pain";

        clvarlt[85]= "skin_issuse";
        clvarlt[86]= "persistant_cough";
        clvarlt[87]= "weight_loss";
        clvarlt[88]= "swol_lymph";
        clvarlt[89]= "bone_pain";
        clvarlt[90]= "rectal_bleed";
        clvarlt[91]= "abdominal_pain";

        clvarlt[93]= "skin_issuse";
        clvarlt[94]= "persistant_cough";
        clvarlt[95]= "weight_loss";
        clvarlt[96]= "swol_lymph";
        clvarlt[97]= "bone_pain";
        clvarlt[98]= "trouble_urine";

        clvarlt[101]= "skin_issuse";
        clvarlt[102]= "persistant_cough";
        clvarlt[103]= "weight_loss";
        clvarlt[104]= "swol_lymph";
        clvarlt[105]= "bone_pain";
        clvarlt[106]= "trouble_urine";
        clvarlt[107]= "blood_urine";

        clvarlt[109]= "skin_issuse";
        clvarlt[110]= "persistant_cough";
        clvarlt[111]= "weight_loss";
        clvarlt[112]= "swol_lymph";
        clvarlt[113]= "bone_pain";
        clvarlt[114]= "trouble_urine";
        clvarlt[115]= "blood_urine";
        clvarlt[116]= "lower_back_pain";

        clvarlt[121]= "skin_issuse";
        clvarlt[122]= "persistant_cough";
        clvarlt[123]= "weight_loss";
        clvarlt[124]= "swol_lymph";
        clvarlt[125]= "bone_pain";
        clvarlt[126]= "trouble_urine";
        clvarlt[127]= "blood_urine";
        clvarlt[128]= "lower_back_pain";

        clvarlt[133]= "skin_issuse";
        clvarlt[134]= "persistant_cough";
        clvarlt[135]= "weight_loss";
        clvarlt[136]= "nausea";
        clvarlt[137]= "bone_pain";
        clvarlt[138]= "rectal_bleed";
        clvarlt[139]= "mouth_ulcer";

        clvarlt[141]= "skin_issuse";
        clvarlt[142]= "persistant_cough";
        clvarlt[143]= "weight_loss";
        clvarlt[144]= "nausea";
        clvarlt[145]= "bone_pain";
        clvarlt[146]= "rectal_bleed";
        clvarlt[147]= "mouth_ulcer";

        clvarlt[149]= "skin_issuse";
        clvarlt[150]= "persistant_cough";
        clvarlt[151]= "weight_loss";
        clvarlt[152]= "nausea";
        clvarlt[153]= "bone_pain";
        clvarlt[154]= "rectal_bleed";

        clvarlt[169]= "skin_issuse";
        clvarlt[170]= "persistant_cough";
        clvarlt[171]= "weight_loss";
        clvarlt[172]= "nausea";
        clvarlt[173]= "bone_pain";
        clvarlt[174]= "trouble_urine";
        clvarlt[175]= "blood_urine";

        clvarlt[177]= "skin_issuse";
        clvarlt[178]= "persistant_cough";
        clvarlt[179]= "weight_loss";
        clvarlt[180]= "nausea";
        clvarlt[181]= "bone_pain";
        clvarlt[182]= "trouble_urine";
        clvarlt[183]= "blood_urine";
        clvarlt[184]= "lower_back_pain";

        clvarlt[189]= "skin_issuse";
        clvarlt[190]= "persistant_cough";
        clvarlt[191]= "weight_loss";
        clvarlt[192]= "nausea";
        clvarlt[193]= "bone_pain";
        clvarlt[194]= "trouble_urine";
        clvarlt[195]= "blood_urine";
        clvarlt[196]= "lower_back_pain";

        clvarlt[201]= "skin_issuse";
        clvarlt[202]= "persistant_cough";
        clvarlt[203]= "weight_loss";
        clvarlt[204]= "nausea";
        clvarlt[205]= "headache";

        clvarlt[209]= "skin_issuse";
        clvarlt[210]= "persistant_cough";
        clvarlt[211]= "weight_loss";
        clvarlt[212]= "nausea";
        clvarlt[213]= "headache";
        clvarlt[214]= "yellow_skin";

        clvarlt[217]= "skin_issuse";
        clvarlt[218]= "persistant_cough";
        clvarlt[219]= "weight_loss";
        clvarlt[220]= "nausea";
        clvarlt[221]= "headache";
        clvarlt[222]= "yellow_skin";
 //------------------------------------------------

}


void NewBackward::determine_member_concl_list() {
/* routine to determine if a variable (varble) is a member of the
   conclusion list (conclt).  if yes return sn != 0.
   if not a member sn=0;
*/
        /* initially set to not a member */
        sn = 0;
        /* member of conclusion list to be searched is f */
        i = f;
        // OLD while((strcmp(varble, conclt[i]) != 0) && (i<8))
        while ((varble != conclt[i]) && (i < conclt.size())) {
            i = i + 1;
            //cout << "Comparing " << varble << ": " << conclt[i] << "\n";
        }
                /* test for membership */

        //if (strcmp(varble, conclt[i]) == 0) sn = i;  /* a member */
        if (varble == conclt[i]) sn = i;
        cout << "sn : " << sn << "\n";
        cout << "i : " << i << "\n";
}

void NewBackward::push_on_stack()
/* routine to push statement number (sn) and a clause number of 1 onto the
conclusion stack which consists of the statement stack (statsk) and the
clause stack (clausk)..to push decrement stack pointer (sp) */
{
        sp=sp-1;
        statsk[sp] = sn;
        clausk[sp] = 1;
}

void printStack() {
    cout << "---------------------\n";
    cout << "sp at : " << sp << "\n";
    cout << "stack top : " << statsk[sp] << "\n";
    cout << "claus top : " << clausk[sp] << "\n";
    cout << "---------------------\n";
}

void NewBackward::instantiate()
/* routine to instantiate a variable (varble) if it isn't already.  the
instantiate indication (instlt) is a 0 if not, a 1 if it is.  the
variable list (varlt) contains the variable (varble). */
{
        i=1;
        /* find variable in the list */
        //OLD while((strcmp(varble, varlt[i]) != 0) && (i<10)) i=i+1;
        while ((varble != varlt[i]) && (i < varlt.size())) {
                i++;
        }
        //OLD if((strcmp(varble, varlt[i]) == 0) && (instlt[i] != 1))
        if ((varble == varlt[i]) && (instlt[i] != 1))
                /*found variable and not already instantiated */
        {
                instlt[i]=1; /*mark instantiated */
                /* the designer of the
               knowledge base places the input statements to
               instantiate the variables below in the case statement */
                switch (i)
                {
                        /***** input statement *****/
                        /* input statements for sample position knowledge
                           base */
                        /***** comment 1700 ******/
                /* OLD
                case 1: printf("INPUT YES OR NOW FOR DE-? ");
                        cin >> de;
                        break;
                case 2: printf("INPUT YES OR NO FOR DI-? ");
                        cin >> di;
                        break;
                case 3: printf("INPUT A REAL NUMBER FOR EX-? ");
                        cin >>  ex;
                        break;
                case 4: printf("INPUT A REAL NUMBER FOR GR-? ");
                        cin >>  gr;
                        break;
                */

                case 1: printf("Do you feel like your skin has changed? (YES/NO) ");
                        cin >> change_skin;
                        break;
                case 2: printf("Do you have dry skin? (YES/NO) ");
                        cin >> dry_skin;
                        break;
                case 3: printf("Do you feel a lump in your breast? (YES/NO) ");
                        cin >>  lump_breast;
                        break;
                case 4: printf("Do you feel like your moles have gotten worse? (YES/NO) ");
                        cin >>  mole_change;
                        break;
                case 5: printf("Are you coughing persistently? (YES/NO) ");
                        cin >> persistant_cough;
                        break;
                case 6: printf("Were you diagnosed with a respiratory infection? (YES/NO) ");
                        cin >> resp_infect;
                        break;
                case 7: printf("Do you cough up blood? (YES/NO) ");
                        cin >>  cough_blood;
                        break;
                case 8: printf("Do you feel like you have difficulty swallowing? (YES/NO) ");
                        cin >>  diff_swallow;
                        break;

                case 9: printf("Have you experienced sudden weight loss? (YES/NO) ");
                        cin >> weight_loss;
                        break;
                case 10: printf("Do you have any swollen lymph nodes? (YES/NO) ");
                        cin >> swol_lymph;
                        break;
                case 11: printf("Do experience pain deep within your bones? (YES/NO) ");
                        cin >>  bone_pain;
                        break;
                case 12: printf("Do you have rectal bleeding or blood after bowel movements? (YES/NO) ");
                        cin >>  rectal_bleed;
                        break;

                case 13: printf("Do you have severe or moderate mouth ulcers? (YES/NO) ");
                        cin >> mouth_ulcer;
                        break;
                case 14: printf("Do you experience frequent abdominal pain? (YES/NO) ");
                        cin >> abdominal_pain;
                        break;
                case 15: printf("Do experience frequent nausea? (YES/NO) ");
                        cin >>  nausea;
                        break;
                case 16: printf("Do you experience headaches? (YES/NO) ");
                        cin >>  headache;
                        break;

                case 17: printf("Has your skin changed to a yellow? (YES/NO) ");
                        cin >> yellow_skin;
                        break;
                case 18: printf("Do you experience problems urinating? (YES/NO) ");
                        cin >> trouble_urine;
                        break;
                case 19: printf("Do have blood in your urine? (YES/NO) ");
                        cin >>  blood_urine;
                        break;
                case 20: printf("Do you experience lower back pain? (YES/NO) ");
                        cin >>  lower_back_pain;
                        break;

                }
                /* end of inputs statements for sample position knowledge
                   base */
        }
}

void NewBackward::ifSwitch()
{
    switch (sn)
    {

        /* if part of statement 1 */
        /* OLD
        case 1: if(de == "NO") s = 1;
                break;
        case 2: if(de == "YES") s = 1;
                break;
        case 3: if((de == "YES") && (di == "YES")) s =1;
                break;
        case 4: if((qu == "YES") && (gr <3.5) && (ex >= 2)) s = 1;
        case 5: if((qu == "YES") && (gr<3) && (ex<2)) s = 1;
                break;
        case 6: if((qu == "YES") && (gr >=3.5)) s = 1;
                break;
        */

        ///* NEW RULES
        // RULE 10
        case 1: if((skin_issuse == "YES") && (lump_breast == "YES") && (mole_change == "NO") ) {
            s = 1;
        }
                cout << "RULE 10 ENACT\n";
                break;
        // RULE 30
        case 2: if((skin_issuse == "YES") && (mole_change == "YES") && (lump_breast == "NO")) {
                s = 1;
                }
                break;
        // RULE 50
        case 3: if((skin_issuse == "YES") && (mole_change == "NO") && (lump_breast == "NO"))  {
                s = 1;
                }
                break;
        // RULE 70
        case 4: if((skin_issuse == "YES") && (persistant_cough == "YES") && (resp_infect == "YES")) {
                s = 1;
                }
                break;
        // RULE 80
        case 5: if((skin_issuse == "NO") && (persistant_cough == "YES") && (resp_infect == "YES") &&
                    (cough_blood == "YES")) {
                s = 1;
                }
                break;
        // RULE 100
        case 6: if((skin_issuse == "NO") && (persistant_cough == "YES") && (resp_infect == "NO") &&
                    (cough_blood == "NO") && (diff_swallow == "NO")) {
                s = 1;
                }
                break;
        // RULE 120
        case 7: if((skin_issuse == "NO") && (persistant_cough == "YES") && (resp_infect == "NO") &&
                    (cough_blood == "NO") && (diff_swallow == "NO")) {
                s = 1;
                }
                break;
        // RULE 140
        case 8: if((skin_issuse == "NO") && (persistant_cough == "NO") && (weight_loss == "NO") &&
                    (swol_lymph == "NO")) {
                s = 1;
                }
                break;
        // RULE 160
        case 9: if((skin_issuse == "NO") && (persistant_cough == "NO") && (weight_loss == "YES") &&
                   (swol_lymph == "NO") && (bone_pain == "NO") && (rectal_bleed == "NO") &&
                   (mouth_ulcer == "YES")) {
                s = 1;
                }
                break;
        // RULE 180
        case 10: if((skin_issuse == "NO") && (persistant_cough == "NO") && (weight_loss == "YES") &&
                   (swol_lymph == "NO") && (bone_pain == "NO") && (rectal_bleed == "NO") &&
                   (mouth_ulcer == "YES")) {
                s = 1;
                }
                break;
        // RULE 200
        case 11: if((skin_issuse == "NO") && (persistant_cough == "NO") && (weight_loss == "YES") &&
                   (swol_lymph == "NO") && (bone_pain == "NO") && (rectal_bleed == "YES") &&
                   (abdominal_pain == "YES")) {
                s = 1;
                }
                break;
        // RULE 220
        case 12: if((skin_issuse == "NO") && (persistant_cough == "NO") && (weight_loss == "YES") &&
                   (swol_lymph == "NO") && (bone_pain == "NO") && (rectal_bleed == "YES") &&
                   (abdominal_pain == "NO")) {
                s = 1;
                }
                break;
        // RULE 240
        case 13: if((skin_issuse == "NO") && (persistant_cough == "NO") && (weight_loss == "YES") &&
                   (swol_lymph == "NO") && (bone_pain == "YES") && (trouble_urine == "NO")) {
                s = 1;
                }
                break;
        // RULE 260
        case 14: if((skin_issuse == "NO") && (persistant_cough == "NO") && (weight_loss == "YES") &&
                   (swol_lymph == "NO") && (bone_pain == "YES") && (trouble_urine == "YES") &&
                   (blood_urine == "NO")) {
                s = 1;
                }
                break;
        // RULE 280
        case 15: if((skin_issuse == "NO") && (persistant_cough == "NO") && (weight_loss == "YES") &&
                   (swol_lymph == "NO") && (bone_pain == "YES") && (trouble_urine == "YES") &&
                   (blood_urine == "YES") && (lower_back_pain == "YES")) {
                s = 1;
                }
                break;
        // RULE 310
        case 16: if((skin_issuse == "NO") && (persistant_cough == "NO") && (weight_loss == "YES") &&
                   (swol_lymph == "NO") && (bone_pain == "YES") && (trouble_urine == "YES") &&
                   (blood_urine == "YES") && (lower_back_pain == "NO")) {
                s = 1;
                }
                break;
        // RULE 340
        case 17: if((skin_issuse == "NO") && (persistant_cough == "NO") && (weight_loss == "NO") &&
                   (nausea == "NO") && (bone_pain == "NO") && (rectal_bleed == "NO") &&
                   (mouth_ulcer == "YES")) {
                s = 1;
                }
                break;
        // RULE 360
        case 18: if((skin_issuse == "NO") && (persistant_cough == "NO") && (weight_loss == "NO") &&
                   (nausea == "NO") && (bone_pain == "NO") && (rectal_bleed == "YES") &&
                   (abdominal_pain == "YES")) {
                s = 1;
                }
                break;
        // RULE 380
        case 19: if((skin_issuse == "NO") && (persistant_cough == "NO") && (weight_loss == "NO") &&
                   (nausea == "NO") && (bone_pain == "NO") && (rectal_bleed == "NO")) {
                s = 1;
                }
                break;
        // RULE 400
        case 20: if((skin_issuse == "NO") && (persistant_cough == "NO") && (weight_loss == "NO") &&
                   (nausea == "NO") && (bone_pain == "YES") && (trouble_urine == "NO")) {
                s = 1;
                }
                break;
        // RULE 430
        case 21: if((skin_issuse == "NO") && (persistant_cough == "NO") && (weight_loss == "NO") &&
                   (nausea == "NO") && (bone_pain == "YES") && (trouble_urine == "YES")
                && (blood_urine == "NO")) {
                s = 1;
                }
                break;
        // RULE 450
        case 22: if((skin_issuse == "NO") && (persistant_cough == "NO") && (weight_loss == "NO") &&
                   (nausea == "NO") && (bone_pain == "YES") && (trouble_urine == "YES")
                && (blood_urine == "YES") && (lower_back_pain == "YES")) {
                s = 1;
                }
                break;
        // RULE 480
        case 23: if((skin_issuse == "NO") && (persistant_cough == "NO") && (weight_loss == "NO") &&
                   (nausea == "NO") && (bone_pain == "YES") && (trouble_urine == "YES")
                && (blood_urine == "YES") && (lower_back_pain == "NO")) {
                s = 1;
                }
                break;
        // RULE 510
        case 24: if((skin_issuse == "NO") && (persistant_cough == "NO") && (weight_loss == "NO") &&
                   (nausea == "YES") && (headache == "YES")) {
                s = 1;
                }
                break;
        // RULE 530
        case 25: if((skin_issuse == "NO") && (persistant_cough == "NO") && (weight_loss == "NO") &&
                   (nausea == "YES") && (headache == "NO") && (yellow_skin == "YES")) {
                s = 1;
                }
                break;
        // RULE 550
        case 26: if((skin_issuse == "NO") && (persistant_cough == "NO") && (weight_loss == "NO") &&
                   (nausea == "YES") && (headache == "NO") && (yellow_skin == "NO")) {
                s = 1;
                }
                break;
        //*/
    }

}

void NewBackward::thenSwitch()
{
    switch (sn)
    {
       /* OLD
        case 1: po = "NO";
                printf("PO=NO\n");
                break;


        case 2: qu = "YES";
                printf("QU=YES\n");
                break;

        case 3: po = "YES";
                printf("PO=RESEARCH\n");
                break;

        case 4: po = "YES";
                printf("PO=SERVICE ENGINEER\n");
                break;

        case 5: po = "NO";
                printf("PO=NO");
                break;

        case 6: po = "YES";
                printf("PO=PRODUCT ENGINEER\n");
                break;
        */
        // RULE 10 THEN
        case 1: cancer = "Breast Cancer";
                printf("Breast Cancer");
                break;
        // RULE 30 THEN
        case 2: cancer = "Skin Cancer";
                printf("Skin Cancer");
                break;
        // RULE 50 THEN
        case 3: cancer = "None diagnosed";
                printf("See doctor for further symptoms.");
                break;
        // RULE 70 THEN
        case 4: cancer = "Lung Cancer";
                printf("Lung Cancer n");
                break;
        // RULE 80 THEN
        case 5: cancer = "Tracheal Cancer";
                printf("Tracheal Cancer");
                break;
        // RULE 100
        case 6: cancer = "None diagnosed";
                printf("See doctor for further symptoms.");
                break;
        // RULE 120 THEN
        case 7: cancer = "Mouth Cancer";
                printf("Mouth Cancer");
                break;
        // RULE 140 THEN
        case 8: cancer = "Leukemia";
                printf("Leukemia");
                break;
        // RULE 160 THEN
        case 9: cancer = "Mouth Cancer";
                printf("Mouth Cancer");
                break;
        // RULE 180 THEN
        case 10: cancer = "None diagnosed";
                printf("See doctor for further symptoms.");
                break;
        // RULE 200 THEN
        case 11: cancer = "Colon Cancer";
                printf("Colon Cancer");
                break;
        // RULE 220
        case 12: cancer = "None diagnosed";
                printf("See doctor for further symptoms.");
                break;
        // RULE 240
        case 13: cancer = "Bone Cancer";
                printf("Bone Cancer");
                break;
        // RULE 260 THEN
        case 14: cancer = "None diagnosed";
                printf("See doctor for further symptoms.");
                break;
        // RULE 280 THEN
        case 15: cancer = "Kidney Cancer";
                printf("Kidney Cancer");
                break;
        // RULE 310 THEN
        case 16: cancer = "Bladder Cancer";
                printf("Bladder Cancer n");
                break;
        // RULE 340 THEN
        case 17: cancer = "Mouth Cancer";
                printf("Mouth Cancer");
                break;
        // RULE 360
        case 18: cancer = "Colon Cancer";
                printf("Colon Cancer");
                break;
        // RULE 380 THEN
        case 19: cancer = "None diagnosed";
                printf("See doctor for further symptoms.");
                break;
        // RULE 400 THEN
        case 20: cancer = "Bone Cancer";
                printf("Bone Cancer");
                break;
        // RULE 430 THEN
        case 21: cancer = "None diagnosed";
                printf("See doctor for further symptoms.");
                break;
        // RULE 450 THEN
        case 22: cancer = "Kidney Cancer";
                printf("Kidney Cancer");
                break;
        // RULE 480 THEN
        case 23: cancer = "Bladder Cancer";
                printf("Bladder Cancer");
                break;
        // RULE 510
        case 24: cancer = "Brain Cancer";
                printf("Brain Cancer");
                break;
        // RULE 530
        case 25: cancer = "Liver Cancer";
                printf("Liver Cancer");
                break;
        // RULE 550
        case 26: cancer = "None diagnosed";
                printf("See doctor for further symptoms.");
                break;

    }
}
void NewBackward::recursive_search() {
        if (sn != 0) {

             do {
                if (recursion == false) {push_on_stack();}
                    recursion = false;
                do {
                    // Loop through to get all conclusions on stack.
                        i= (statsk[sp] -1) *4 + clausk[sp];
                        /* clause variable */
                        varble = clvarlt[i];
                        if(varble != "") {
                      /*is this clause variable a conclusion? */
                            f = 1;
                            determine_member_concl_list();
                            if (sn != 0) {
                                push_on_stack();
                                //cout << "continue";
                                f=1;
                                determine_member_concl_list();
                                break;
                            }
                            instantiate();
                            clausk[sp] = clausk[sp] + 1;
                        }

                } while (varble != "");
                sn = statsk[sp];
                s = 0;
                ifSwitch();
                if( s != 1) {
                    /* failed..search rest of statements for
                        same conclusion */
                    /* get conclusion */
                    //printStack();
                    i = statsk[sp];
                    //cout << "if (s!= 1) i : " << i << "\n";
                   varble = conclt[i];
                   /* search for conclusion starting at the
                     next statement number */
                   f = statsk[sp] + 1;
                   determine_member_concl_list();
                   sp = sp+1;
                  }
            } while ((s != 1) && (sn !=0));

            if (sn != 0) {
                thenSwitch();
                sp = sp + 1;
                if ((sp >= statsk.size()) || (cancer != "")) {
                    printf("*** SUCCESS\n");

                } else {
                    clausk[sp] = clausk[sp]+1;
                    recursion = true;
                    recursive_search();
                }

            }
        }
}
