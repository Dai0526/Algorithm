const governmentForms = [{
    name: "Plutocracy",
    definition: "Rule by the wealthy"
},
{
    name: "Oligarchy",
    definition: "Rule by a small number of people"
},
{
    name: "Kleptocracy",
    definition: "Rule by the thieves"
},
{
    name: "Theocracy",
    definition: "Rule by a religious elite"
},
{
    name: "Democracy",
    definition: "Rule by the people"
},
{
    name: "Autocracy",
    definition: "Rule by a single person"
}];

// Complete the following program to compute and return the names of political forms ending with "cy".
function endCy(governmentForms){
    var cyList = [];
    for(const f of governmentForms){
        //const len = f.name.length;
        //const char1 = f.name.charAt(len - 2);
        //const char2 = f.name.charAt(len - 1);

        if(f.name.endsWith("cy")){
            cyList.push(f.name);
        }
    }
    return cyList;
}

const cyList = endCy(governmentForms);
console.log(cyList);