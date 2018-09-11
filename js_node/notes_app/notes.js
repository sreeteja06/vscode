const fs = require('fs');

const fetchNotes = () => {
    try {
        return JSON.parse(fs.readFileSync('notes.json'));
    } catch (e) {
        return [];
    }
}

const saveNotes = (notes) => {
    fs.writeFile('notes.json', JSON.stringify(notes), function (err) {
        if (err) {
            console.log(err);
        }
    });
}

const addNote = (title,body) => {
    var notes = fetchNotes();
    var note = {
        title,
        body
    };
    for(i=0;i<notes.length;i++){
        if(notes[i].title==title){
            return console.log('note with same title already exists');
        }
    }
    notes.push(note);
    saveNotes(notes);
    return note;
}

const getAll = () => {
    return fetchNotes();
    // console.log("getting all notes");
}

const getNote = (title) => {
    let notes = fetchNotes();
    let filteredNotes = notes.filter((note)=>note.title===title);
    return filteredNotes;
}

const removeNote = (title) => {
    let notes = fetchNotes();
    let filteredNotes = notes.filter((note)=>note.title!=title);
    saveNotes(filteredNotes);
    console.log("deleting note with title", title);
}

module.exports = {
    addNote,
    getAll,
    getNote,
    removeNote
}