const builder = require('botbuilder');
const restify = require('restify');
//create bot
const connector = new builder.ChatConnector();
const bot = new builder.UniversalBot(
    connector,
    [
        (session) => {                          //is equal to function(session) {}
            builder.Prompts.text(session, `hello,what is your name`);
        },
        (session, results) =>{
            session.endDialog(`hello, ${results.response}`);        //session.send('hello bots');
        }
    ]
);
//create the bot web server
const server = restify.createServer();
server.post('/api/messages', connector.listen());
server.listen(
    process.env.PORT || 3978,
    () => console.log('server up!!')
)