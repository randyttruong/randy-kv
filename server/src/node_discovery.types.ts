/*
 * node_discovery.types.ts
 *
 * This file contains the types for the node discovery service.
 * It contains the types for the Node and the NodeStore, as well
 * as the request and response types for the various endpoints.
 *
 * Note: These types are shared between the server and the client.
 * Additionally, these types are consistent with the proto file.
 */

export enum NodeStatus {
    HEALTHY = 'healthy',
    UNHEALTHY = 'unhealthy',
    OFFLINE = 'offline',
    UNKNOWN = 'unknown'
}

export interface Node {
    id: string;
    address: string;
    port: number;
    status: NodeStatus;
    lastHeartbeat?: string;
}

export interface NodeStore {
    [id: string]: Node;
}

// `/register` - RegisterNode
export interface RegisterNodeRequest {
    id: string;
    address: string;
    port: number;
}

export interface RegisterNodeResponse {
    success: boolean;
    message: string;
}

// `/deregister/` - DeregisterNode
export interface DeregisterNodeRequest {
    id: string;
}
export interface DeregisterNodeResponse {
    success: boolean;
    message: string;
}

// `/heartbeat/` - Heartbeat
export interface HeartbeatRequest {
    id: string;
}
export interface HeartbeatResponse {
    success: boolean;
    message: string;
}

// `/nodes/` - GetNodes
export interface GetNodesRequest {}
export interface GetNodesResponse {
    nodes: NodeStore;
}

// `/peers/` - GetPeers
export interface GetPeersRequest {
    id: string;
}

export interface GetPeersResponse {
    peers: NodeStore;
}


// `/nodes/status/` - GetNodeStatus
export interface GetNodeStatusRequest {
    id: string;
}
export interface GetNodeStatusResponse {
    status: NodeStatus;
}


// `/update-metadata/` - UpdateNodeMetadata
export interface UpdateNodeMetadataRequest {
    id: string;
    address?: string;
    port?: number;
}
export interface UpdateNodeMetadataResponse {
    success: boolean;
    message: string;
}