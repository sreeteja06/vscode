const fs = require('fs');
const _ = require('lodash');
const yargs = require('yargs');

const notes = require('./notes');

const title ={
    describe: 'title of note',
    demand:true,
    alias: 't'
};

const body = {
    describe: 'note description',
    demand: true,
    alias: 'b'
}

const argv = yargs
.command('add','add a new note',{
    title,
    body
})
.command('list','listing all the notes')
.command('read')
.help()
.argv;
if (argv._[0] == 'add'){
    let note = notes.addNote(argv.title,argv.body);
    if(note!=null){
        console.log("successfully added",note);
    }
    else{
        console.log("some error");
    }
}
else if (argv._[0] == 'list'){
    const allnote = notes.getAll();
    allnote.forEach((element) => {
        console.log(element.body);
    });
}
else if (argv._[0] == 'remove'){
    notes.removeNote(argv.title);
}
else if (argv._[0] == 'read'){
    const note = notes.getNote(argv.title);
    if(note>=0){
        console.log("error getting note");
    }
    else{
        console.log(note[0].title+":"+note[0].body);
    }
}
else{
    console.log("command not found");
}