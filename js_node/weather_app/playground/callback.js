var getUser = (id, callback) => {
    var user = {
        id,
        name: 'sree'
    };
    setTimeout(() => {
        callback(user);
    }, 3000);
};

getUser(31, (user) => {
    console.log(user);
});
console.log('hello');