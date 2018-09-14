
const asynAdd = (a,b) =>{
    return new Promise((resolve, reject) => {
        setTimeout(()=>{
            if(typeof a === 'number' && typeof b === 'number'){
                resolve(a+b);
            }
            else {
                reject('argunments must be numbers');
            }
        },1500);
    });
};

asynAdd(5,7).then((message)=>{
    console.log(message);
    return asynAdd(message,33);
}).then((res)=>{
    console.log(res)
}).catch((errMsg)=>{
    console.log(errMsg);
})

// let somePromise = new Promise((resolve, reject)=>{
//     setTimeout(()=>{
//         //resolve("it worked");
//         reject("error");
//     },2500);
// });
// somePromise.then((message)=>{
//     console.log('sucess',message);
// },(errMsg)=> {
//     console.log(errMsg);
// })