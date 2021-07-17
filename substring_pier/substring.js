module.exports = function(RED) {
    function substringNode(config) {
        RED.nodes.createNode(this,config);
        var node = this;
        node.on('input', function(msg) {
            msg.payload = msg.payload.substring(0,msg.topic);
            node.send(msg);
        });
    }
    RED.nodes.registerType("substring2-pier",substringNode);
}